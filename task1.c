// Name: Hadia Anjum
// Reg#: 23-NTU-CS-1161
// Task: Task 1 - Thread Information Display

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void* thread_func(void* arg) {
    int num = *(int*)arg;
    pthread_t tid = pthread_self();
    printf("Thread %d: pthread_self() = %lu\n", num, (unsigned long)tid);

    // random sleep between 1-3
    int t = (rand() % 3) + 1;
    printf("Thread %d: sleeping %d seconds...\n", num, t);
    sleep(t);

    printf("Thread %d: completed after %d seconds.\n", num, t);
    free(arg);
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t threads[5];

    for (int i = 0; i < 5; ++i) {
        int *arg = malloc(sizeof(int));
        *arg = i+1; // thread number 1..5
        if (pthread_create(&threads[i], NULL, thread_func, arg) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    // join threads
    for (int i = 0; i < 5; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("Main: All threads joined.\n");
    return 0;
}
