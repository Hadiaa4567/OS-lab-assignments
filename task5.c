// Name: Hadia Anjum
// Reg#: 23-NTU-CS-1161
// Task: Task 5 - Struct Based Thread Communication

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
    int student_id;
    char name[50];
    float gpa;
} Student;

int deans_count = 0;
pthread_mutex_t lock;

void* process_student(void* arg) {
    Student *s = (Student*)arg;
    printf("Student ID: %d\nName: %s\nGPA: %.2f\n", s->student_id, s->name, s->gpa);
    if (s->gpa >= 3.5) {
        printf("%s is on the Dean's List.\n", s->name);
        pthread_mutex_lock(&lock);
        deans_count++;
        pthread_mutex_unlock(&lock);
    } else {
        printf("%s is NOT on the Dean's List.\n", s->name);
    }
    free(s); // we malloc before passing
    return NULL;
}

int main() {
    pthread_t tids[3];
    pthread_mutex_init(&lock, NULL);

    // Create three students (example data)
    Student *s1 = malloc(sizeof(Student));
    s1->student_id = 101; strcpy(s1->name, "Aisha"); s1->gpa = 3.7;

    Student *s2 = malloc(sizeof(Student));
    s2->student_id = 102; strcpy(s2->name, "Bilal"); s2->gpa = 3.2;

    Student *s3 = malloc(sizeof(Student));
    s3->student_id = 103; strcpy(s3->name, "Sara"); s3->gpa = 3.9;

    pthread_create(&tids[0], NULL, process_student, s1);
    pthread_create(&tids[1], NULL, process_student, s2);
    pthread_create(&tids[2], NULL, process_student, s3);

    for (int i = 0; i < 3; ++i) pthread_join(tids[i], NULL);

    printf("Main: Number of students on Dean's List = %d\n", deans_count);

    pthread_mutex_destroy(&lock);
    return 0;
}
