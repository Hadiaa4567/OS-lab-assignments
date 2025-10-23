// Name: Hadia Anjum
// Reg#: 23-NTU-CS-1161
// Task: Task 2 - Personalized Greeting Thread

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void* greet(void* arg) {
    char* name = (char*)arg;
    printf("Thread says: Hello, %s! Welcome to the world of threads.\n", name);
    return NULL;
}

int main() {
    pthread_t tid;
    char *name = "Hadia"; // you can also read from stdin and strdup it
    printf("Main thread: Waiting for greeting...\n");
    if (pthread_create(&tid, NULL, greet, (void*)name) != 0) {
        perror("pthread_create");
        return 1;
    }
    pthread_join(tid, NULL);
    printf("Main thread: Greeting completed.\n");
    return 0;
}
