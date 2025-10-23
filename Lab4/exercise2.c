#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

typedef struct {
    int number;
} ThreadArg;

void* check_prime(void* arg) {
    ThreadArg* data = (ThreadArg*)arg;
    int n = data->number;

    int* result = malloc(sizeof(int));  // 1 = prime, 0 = not prime

    if (n <= 1) {
        *result = 0;
        return result;
    }
    if (n == 2) {
        *result = 1;
        return result;
    }
    if (n % 2 == 0) {
        *result = 0;
        return result;
    }

    int limit = (int)sqrt((double)n);
    *result = 1; // assume prime
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) {
            *result = 0;
            break;
        }
    }
    return result;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    pthread_t tid;
    ThreadArg arg = { .number = num };
    int* is_prime;

    // Create a thread to check primality
    if (pthread_create(&tid, NULL, check_prime, &arg) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Wait for thread and get result
    pthread_join(tid, (void**)&is_prime);

    if (*is_prime)
        printf("%d is a PRIME number.\n", num);
    else
        printf("%d is NOT a prime number.\n", num);

    free(is_prime);
    return 0;
}
