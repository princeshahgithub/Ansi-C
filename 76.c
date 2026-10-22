#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int id;
    float grade;
} Student;

void print_menu() {
    printf("\n=== Student Database ===\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Calculate Average Grade\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    Student db[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        if (choice == 1) {
            if (count >= MAX_STUDENTS) {
                printf("Database full!\n");
                continue;
            }
            printf("Enter name: ");
            scanf("%s", db[count].name);
            printf("Enter ID: ");
            scanf("%d", &db[count].id);
            printf("Enter grade: ");
            scanf("%f", &db[count].grade);
            count++;
            printf("Student added successfully.\n");
        } else if (choice == 2) {
            if (count == 0) {
                printf("No records found.\n");
                continue;
            }
            printf("\nID\tName\t\tGrade\n");
            printf("-------------------------------\n");
            for (int i = 0; i < count; i++) {
                printf("%d\t%-15s%.2f\n", db[i].id, db[i].name, db[i].grade);
            }
        } else if (choice == 3) {
            if (count == 0) {
                printf("No students to average.\n");
                continue;
            }
            float sum = 0;
            for (int i = 0; i < count; i++) {
                sum += db[i].grade;
            }
            printf("Class Average: %.2f\n", sum / count);
        } else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

