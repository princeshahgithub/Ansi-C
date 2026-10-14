#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Line 5: Define a basic structure for student data
struct Student {
    int id;
    char name[50];
    float gpa;
};

// Line 11: Function to print student details
void printStudent(struct Student s) {
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("GPA: %.2f\n", s.gpa);
}

// Line 18: Function to check passing status
int isPassing(float gpa) {
    if (gpa >= 2.0) {
        return 1;
    } else {
        return 0;
    }
}

// Line 27: Main function starts here
int main() {
    printf("--- Welcome to the 84-Line C Program ---\n");

    // Line 30: Initialize array of structures
    struct Student classroom[3];

    // Line 33: Populate student 1
    classroom[0].id = 101;
    strcpy(classroom[0].name, "Alice");
    classroom[0].gpa = 3.8;

    // Line 38: Populate student 2
    classroom[1].id = 102;
    strcpy(classroom[1].name, "Bob");
    classroom[1].gpa = 1.7;

    // Line 43: Populate student 3
    classroom[2].id = 103;
    strcpy(classroom[2].name, "Charlie");
    classroom[2].gpa = 3.2;

    // Line 48: Dynamic memory allocation practice
    int *dynamicArray = (int *)malloc(5 * sizeof(int));
    if (dynamicArray == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Line 55: Loop to populate dynamic memory array
    for (int i = 0; i < 5; i++) {
        dynamicArray[i] = (i + 1) * 10;
    }

    printf("Dynamic array contents:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n\n");

    // Line 66: Display all student details and pass status
    printf("Student Records:\n");
    for (int i = 0; i < 3; i++) {
        printStudent(classroom[i]);
        if (isPassing(classroom[i].gpa)) {
            printf("Status: Passing\n");
        } else {
            printf("Status: Failing\n");
        }
        printf("--------------------\n");
    }

    // Line 78: Clean up dynamically allocated memory
    free(dynamicArray);

    printf("Program finished successfully.\n");
    return 0;
}

