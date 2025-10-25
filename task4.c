// Name: Hadia Anjum
// Reg#: 23-NTU-CS-1161
// Task: Task 4 - Thread Return Values (factorial)

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* factorial(void* arg) {
    int n = *(int*)arg;
    unsigned long long *res = malloc(sizeof(unsigned long long));
    *res = 1ULL;
    for (int i = 2; i <= n; ++i) *res *= i;
    free(arg);
    // return pointer to result
    return (void*)res;
}

int main() {
    pthread_t tid;
    int *n = malloc(sizeof(int));
    printf("Enter n (0-20 recommended): ");
    scanf("%d", n);

    if (pthread_create(&tid, NULL, factorial, n) != 0) {
        perror("pthread_create");
        return 1;
    }

    unsigned long long *result;
    pthread_join(tid, (void**)&result);
    printf("Factorial = %llu\n", *result);
    free(result);
    return 0;
}