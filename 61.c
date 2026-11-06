#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

void printMenu() {
    printf("\n=== Student Database ===\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by ID\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}

int main() {
    Student db[MAX_STUDENTS];
    int count = 0, choice, searchId, found;
    while (1) {
        printMenu();
        if (scanf("%d", &choice) != 1) break;
        if (choice == 4) break;
        switch (choice) {
            case 1:
                if (count >= MAX_STUDENTS) {
                    printf("Database full!\n");
                    break;
                }
                printf("Enter ID, Name, GPA: ");
                scanf("%d %s %f", &db[count].id, db[count].name, &db[count].gpa);
                count++;
                break;
            case 2:
                printf("\nID\tName\tGPA\n---------------------\n");
                for (int i = 0; i < count; i++)
                    printf("%d\t%s\t%.2f\n", db[i].id, db[i].name, db[i].gpa);
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &searchId);
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (db[i].id == searchId) {
                        printf("Found: %s, GPA: %.2f\n", db[i].name, db[i].gpa);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Student not found.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
