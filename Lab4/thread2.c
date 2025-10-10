// file: pass_arg.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_number(void* arg) {
    int num = *(int*)arg;
    printf("Thread received number: %d\n", num);
    printf("Square: %d\n", num * num);
    return NULL;
}

int main() {
    pthread_t tid;
    int number = 42;

    printf("Creating thread with argument: %d\n", number);
    if (pthread_create(&tid, NULL, print_number, &number) != 0) {
        perror("pthread_create");
        return 1;
    }

    pthread_join(tid, NULL);
    printf("Main thread done.\n");
    return 0;
}
