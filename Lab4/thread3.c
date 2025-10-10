// file: three_threads.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* worker(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d started. Thread ID (sys): %lu\n", id, (unsigned long)pthread_self());
    printf("Thread %d says: Hello from thread %d\n", id, id);
    return NULL;
}

int main() {
    const int N = 3;
    pthread_t threads[N];
    int ids[N];

    for (int i = 0; i < N; ++i) {
        ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, worker, &ids[i]) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    for (int i = 0; i < N; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("Main: all threads completed.\n");
    return 0;
}
