#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

typedef struct {
    char name[50];
    float score;
    char grade;
} Student;

char calculate_grade(float score) {
    if (score >= 90.0) return 'A';
    if (score >= 80.0) return 'B';
    if (score >= 70.0) return 'C';
    if (score >= 60.0) return 'D';
    return 'F';
}

void print_separator(void) {
    printf("---------------------------------------\n");
}

int main(void) {
    Student students[MAX_STUDENTS] = {
        {"Alice Smith", 92.5, ' '},
        {"Bob Jones", 78.0, ' '},
        {"Charlie Brown", 88.5, ' '},
        {"Diana Prince", 95.0, ' '},
        {"Evan Wright", 64.0, ' '}
    };

    float total_score = 0.0;
    int top_student_index = 0;
    float highest_score = 0.0;

    for (int i = 0; i < MAX_STUDENTS; i++) {
        students[i].grade = calculate_grade(students[i].score);
        total_score += students[i].score;

        if (students[i].score > highest_score) {
            highest_score = students[i].score;
            top_student_index = i;
        }
    }

    float class_average = total_score / MAX_STUDENTS;

    printf("\n=== STUDENT GRADE REPORT ===\n");
    print_separator();
    printf("%-20s | %-6s | %-5s\n", "Name", "Score", "Grade");
    print_separator();

    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("%-20s | %-6.1f | %-5c\n", 
               students[i].name, 
               students[i].score, 
               students[i].grade);
    }

    print_separator();
    printf("Class Average: %.2f%%\n", class_average);
    printf("Top Performer: %s (%.1f%%)\n", 
           students[top_student_index].name, 
           students[top_student_index].score);
    print_separator();

    return 0;
}

