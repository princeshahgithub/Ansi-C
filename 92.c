
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    float gpa;
} Student;

void print_menu() {
    printf("\n=== Student Database ===\n");
    printf("1. Add Student\n");
    printf("2. List Students\n");
    printf("3. Search Student by ID\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}

int main() {
    Student db[MAX_STUDENTS];
    int count = 0;
    int choice;
    int search_id;
    int found;

    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        if (choice == 4) {
            printf("Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                if (count >= MAX_STUDENTS) {
                    printf("Database full!\n");
                    break;
                }
                printf("Enter ID: ");
                scanf("%d", &db[count].id);
                printf("Enter Name: ");
                scanf(" %49[^\n]", db[count].name);
                printf("Enter GPA: ");
                scanf("%f", &db[count].gpa);
                count++;
                printf("Student added successfully.\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No students in database.\n");
                    break;
                }
                printf("\n%-5s %-20s %-5s\n", "ID", "Name", "GPA");
                for (int i = 0; i < count; i++) {
                    printf("%-5d %-20s %-5.2f\n", db[i].id, db[i].name, db[i].gpa);
                }
                break;

            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &search_id);
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (db[i].id == search_id) {
                        printf("\nStudent Found:\n");
                        printf("ID: %d\nName: %s\nGPA: %.2f\n", db[i].id, db[i].name, db[i].gpa);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Student with ID %d not found.\n", search_id);
                }
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
