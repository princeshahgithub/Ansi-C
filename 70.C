#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

void addStudent(const char *filename) {
    FILE *file = fopen(filename, "ab");
    if (!file) return;
    struct Student s;
    printf("Enter ID, Name, GPA: ");
    if (scanf("%d %49s %f", &s.id, s.name, &s.gpa) == 3) {
        fwrite(&s, sizeof(struct Student), 1, file);
        printf("Record added successfully!\n");
    }
    fclose(file);
}

void displayStudents(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("No records found.\n");
        return;
    }
    struct Student s;
    printf("\nID\tName\t\tGPA\n-------------------------\n");
    while (fread(&s, sizeof(struct Student), 1, file) == 1) {
        printf("%d\t%-15s\t%.2f\n", s.id, s.name, s.gpa);
    }
    fclose(file);
}

int main() {
    const char *filename = "students.dat";
    int choice;
    while (1) {
        printf("\n=== Student Database ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        if (choice == 1) {
            addStudent(filename);
        } else if (choice == 2) {
            displayStudents(filename);
        } else if (choice == 3) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

