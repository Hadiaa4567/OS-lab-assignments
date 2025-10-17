#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function executed by each thread
void* print_message(void* arg) {
    int thread_num = *(int*)arg;
    printf("Thread %d started. ID: %lu\n", thread_num, (unsigned long)pthread_self());
    printf("Thread %d says: Hello from thread %d!\n", thread_num, thread_num);
    return NULL;
}

int main() {
    const int N = 3;                 // Number of threads
    pthread_t threads[N];
    int ids[N];

    // Create 3 threads
    for (int i = 0; i < N; i++) {
        ids[i] = i + 1;  // Assign thread number
        if (pthread_create(&threads[i], NULL, print_message, &ids[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Main thread: All threads have completed.\n");
    return 0;
}
