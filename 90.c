#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float gpa;
} Student;

void printMenu() {
    printf("\n=== Student Management System ===\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Find Top Student\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        printMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        if (choice == 4) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                if (count >= MAX_STUDENTS) {
                    printf("Database is full!\n");
                    break;
                }
                printf("Enter Student ID: ");
                scanf("%d", &students[count].id);
                printf("Enter Student Name: ");
                scanf(" %[^\n]", students[count].name);
                printf("Enter Student GPA: ");
                scanf("%f", &students[count].gpa);
                count++;
                printf("Student added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No student records available.\n");
                    break;
                }
                printf("\n--- Student Records ---\n");
                for (int i = 0; i < count; i++) {
                    printf("ID: %d | Name: %s | GPA: %.2f\n", 
                           students[i].id, students[i].name, students[i].gpa);
                }
                break;

            case 3:
                if (count == 0) {
                    printf("No student records available.\n");
                    break;
                }
                int topIdx = 0;
                for (int i = 1; i < count; i++) {
                    if (students[i].gpa > students[topIdx].gpa) {
                        topIdx = i;
                    }
                }
                printf("\nTop Student: %s (ID: %d) with GPA: %.2f\n", 
                       students[topIdx].name, students[topIdx].id, students[topIdx].gpa);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

