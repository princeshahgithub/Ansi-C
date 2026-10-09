
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STUDENTS 3

typedef struct {
    int id;
    char name[50];
    float score;
} Student;

void print_banner(void) {
    printf("========================================\n");
    printf("       88 LINES OF C PROGRAMMING        \n");
    printf("========================================\n");
}

float compute_average(const float *arr, int count) {
    if (count <= 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < count; i++) {
        sum += arr[i];
    }
    return sum / (float)count;
}

void init_student(Student *s, int id, const char *name, float score) {
    s->id = id;
    strncpy(s->name, name, sizeof(s->name) - 1);
    s->name[sizeof(s->name) - 1] = '\0';
    s->score = score;
}

int main(void) {
    print_banner();

    Student group[MAX_STUDENTS];
    init_student(&group[0], 101, "Alice", 88.5f);
    init_student(&group[1], 102, "Bob", 94.0f);
    init_student(&group[2], 103, "Charlie", 79.5f);

    float grades[MAX_STUDENTS];
    for (int i = 0; i < MAX_STUDENTS; i++) {
        grades[i] = group[i].score;
        printf("ID: %d | Name: %-8s | Score: %.2f\n",
               group[i].id, group[i].name, group[i].score);
    }

    float mean = compute_average(grades, MAX_STUDENTS);
    printf("----------------------------------------\n");
    printf("Class Average Score: %.2f\n", mean);

    int *buffer = (int *)malloc(5 * sizeof(int));
    if (buffer != NULL) {
        for (int i = 0; i < 5; i++) {
            buffer[i] = (i + 1) * 20;
        }
        printf("Dynamic Alloc Array: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", buffer[i]);
        }
        printf("\n");
        free(buffer);
    }

    printf("========================================\n");
    printf("Execution completed successfully.\n");
    return 0;
}
