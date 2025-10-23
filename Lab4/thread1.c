// file: simple_thread.c
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Hello from new thread!\n");
    printf("New Thread ID: %lu\n", (unsigned long)pthread_self());
    return NULL;
}

int main() {
    pthread_t tid;
    printf("Main thread starting...\n");
    printf("Main Thread ID: %lu\n", (unsigned long)pthread_self());

    if (pthread_create(&tid, NULL, thread_function, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    pthread_join(tid, NULL);
    printf("Main thread exiting...\n");
    return 0;
}
