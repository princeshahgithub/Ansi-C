#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

struct Student {
    int id;
    char name[50];
    float gpa;
};

void displayStudent(struct Student s) {
    printf("ID: %d | Name: %-15s | GPA: %.2f\n", s.id, s.name, s.gpa);
}

int main() {
    struct Student database[MAX_STUDENTS] = {
        {101, "Alice Smith", 3.85},
        {102, "Bob Jones", 3.21},
        {103, "Charlie Brown", 3.90},
        {104, "Diana Prince", 3.65},
        {105, "Evan Wright", 2.95}
    };

    int choice;
    int searchId;
    int found = 0;

    printf("=== Student Records Database ===\n");
    printf("1. View All Students\n");
    printf("2. Search Student by ID\n");
    printf("Enter choice (1-2): ");
    
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("\n");

    if (choice == 1) {
        for (int i = 0; i < MAX_STUDENTS; i++) {
            displayStudent(database[i]);
        }
    } else if (choice == 2) {
        printf("Enter Student ID to find: ");
        scanf("%d", &searchId);
        for (int i = 0; i < MAX_STUDENTS; i++) {
            if (database[i].id == searchId) {
                displayStudent(database[i]);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Student with ID %d not found.\n", searchId);
        }
    } else {
        printf("Invalid choice option.\n");
    }

    return 0;
}

