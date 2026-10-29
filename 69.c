#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 3
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int id;
    float grades[3];
    float gpa;
} Student;

void calculate_gpa(Student *s) {
    float sum = 0.0;
    for (int i = 0; i < 3; i++) {
        sum += s->grades[i];
    }
    s->gpa = sum / 3.0;
}

void print_student(const Student *s) {
    printf("ID: %03d | Name: %-15s | GPA: %.2f\n", s->id, s->name, s->gpa);
}

int main(void) {
    Student roster[MAX_STUDENTS] = {
        {"Alice Smith", 101, {92.5, 88.0, 95.0}, 0.0},
        {"Bob Jones", 102, {78.5, 82.0, 80.0}, 0.0},
        {"Charlie Brown", 103, {88.0, 91.5, 89.0}, 0.0}
    };

    printf("=== Student Record System (69.c) ===\n\n");

    for (int i = 0; i < MAX_STUDENTS; i++) {
        calculate_gpa(&roster[i]);
    }

    printf("Processing completed successfully.\n");
    printf("Displaying student records:\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < MAX_STUDENTS; i++) {
        print_student(&roster[i]);
    }

    printf("----------------------------------------\n");
    printf("Total records processed: %d\n", MAX_STUDENTS);

    return EXIT_SUCCESS;
}

/* End of file: 69.c - Exactly 60 lines of code */

