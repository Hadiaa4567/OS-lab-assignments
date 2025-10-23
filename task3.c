// Name: Hadia Anjum
// Reg#: 23-NTU-CS-1161
// Task: Task 3 - Number Info Thread

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* number_info(void* arg) {
    int n = *(int*)arg;
    printf("Thread: number = %d\n", n);
    printf("Thread: square = %d\n", n * n);
    printf("Thread: cube = %d\n", n * n * n);
    free(arg);
    return NULL;
}

int main() {
    pthread_t tid;
    int *n = malloc(sizeof(int));
    printf("Enter an integer: ");
    scanf("%d", n);

    if (pthread_create(&tid, NULL, number_info, n) != 0) {
        perror("pthread_create");
        return 1;
    }
    pthread_join(tid, NULL);
    printf("Main thread: Work completed.\n");
    return 0;
}
