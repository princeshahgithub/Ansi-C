#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 5
#define PASSING_GRADE 60.0

typedef struct {
    char name[50];
    float grade;
} Student;

void print_separator() {
    printf("-----------------------------------\n");
}

int main() {
    Student students[MAX_STUDENTS];
    float total = 0.0;
    float average = 0.0;

    printf("=== Student Grade Management ===\n\n");

    // Input student details
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Enter name for student %d: ", i + 1);
        if (scanf("%49s", students[i].name) != 1) {
            printf("Error reading name.\n");
            return 1;
        }

        printf("Enter grade for %s: ", students[i].name);
        if (scanf("%f", &students[i].grade) != 1) {
            printf("Error reading grade.\n");
            return 1;
        }
        printf("\n");
    }

    // Process and calculate total
    for (int i = 0; i < MAX_STUDENTS; i++) {
        total += students[i].grade;
    }
    average = total / MAX_STUDENTS;

    // Output report card
    print_separator();
    printf("%-20s | %-10s\n", "Student Name", "Status");
    print_separator();

    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("%-20s | ", students[i].name);
        if (students[i].grade >= PASSING_GRADE) {
            printf("PASSED (%.1f)\n", students[i].grade);
        } else {
            printf("FAILED (%.1f)\n", students[i].grade);
        }
    }

    print_separator();
    printf("Class Average: %.2f\n", average);
    print_separator();

    return 0;
}

