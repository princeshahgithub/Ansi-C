#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 5

struct Student {
    int id;
    char name[30];
    float grade;
};

void printHeader() {
    printf("====================================\n");
    printf("   STUDENT GRADE MANAGEMENT SYSTEM  \n");
    printf("====================================\n");
}

void inputStudents(struct Student s[], int count) {
    for (int i = 0; i < count; i++) {
        s[i].id = i + 1;
        printf("Enter name for student %d: ", s[i].id);
        scanf("%29s", s[i].name);
        printf("Enter grade for student %d: ", s[i].id);
        scanf("%f", &s[i].grade);
    }
}

float calculateAverage(struct Student s[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += s[i].grade;
    }
    return sum / count;
}

void displayReport(struct Student s[], int count) {
    printf("\n--- GRADE REPORT ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %-15s | Grade: %.2f\n", s[i].id, s[i].name, s[i].grade);
    }
    float avg = calculateAverage(s, count);
    printf("--------------------\n");
    printf("Class Average: %.2f\n", avg);
}

int main() {
    struct Student classList[MAX_STUDENTS];
    printHeader();
    inputStudents(classList, MAX_STUDENTS);
    displayReport(classList, MAX_STUDENTS);
    printf("====================================\n");
    printf("Program finished successfully.\n");
    return 0;
}

