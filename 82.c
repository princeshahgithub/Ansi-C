#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define PASSING_GRADE 60.0

typedef struct {
    char name[MAX_NAME];
    int id;
    float grades[3];
    float average;
} Student;

void calculate_average(Student *s) {
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += s->grades[i];
    }
    s->average = sum / 3.0;
}

void print_student_info(const Student *s) {
    printf("ID: %04d | Name: %-15s | Avg: %.2f | Status: ", 
           s->id, s->name, s->average);
    if (s->average >= PASSING_GRADE) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }
}

int main() {
    int student_count = 3;
    Student *classroom = (Student *)malloc(student_count * sizeof(Student));

    if (classroom == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    strcpy(classroom[0].name, "Alice Smith");
    classroom[0].id = 101;
    classroom[0].grades[0] = 85.5;
    classroom[0].grades[1] = 90.0;
    classroom[0].grades[2] = 78.0;

    strcpy(classroom[1].name, "Bob Jones");
    classroom[1].id = 102;
    classroom[1].grades[0] = 55.0;
    classroom[1].grades[1] = 48.5;
    classroom[1].grades[2] = 62.0;

    strcpy(classroom[2].name, "Charlie Brown");
    classroom[2].id = 103;
    classroom[2].grades[0] = 92.0;
    classroom[2].grades[1] = 88.0;
    classroom[2].grades[2] = 95.5;

    printf("--- Processing Classroom Records ---\n");
    for (int i = 0; i < student_count; i++) {
        calculate_average(&classroom[i]);
    }

    printf("\n--- Final Student Roster ---\n");
    for (int i = 0; i < student_count; i++) {
        print_student_info(&classroom[i]);
    }

    float class_sum = 0.0;
    for (int i = 0; i < student_count; i++) {
        class_sum += classroom[i].average;
    }
    printf("\nOverall Class Average: %.2f\n", class_sum / student_count);

    free(classroom);
    classroom = NULL;

    return 0;
}

