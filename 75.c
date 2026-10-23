#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 50
#define TASK_LEN 100

typedef struct {
    char description[TASK_LEN];
    int completed;
} Task;

void displayMenu() {
    printf("\n--- TODO LIST MANAGER ---\n");
    printf("1. Add a New Task\n");
    printf("2. View All Tasks\n");
    printf("3. Exit Program\n");
    printf("Enter your choice (1-3): ");
}

void addTask(Task list[], int *count) {
    if (*count >= MAX_TASKS) {
        printf("\n[Error] Todo list is full!\n");
        return;
    }
    printf("\nEnter task description: ");
    getchar(); // Clear buffer
    fgets(list[*count].description, TASK_LEN, stdin);
    list[*count].description[strcspn(list[*count].description, "\n")] = 0;
    list[*count].completed = 0;
    (*count)++;
    printf("[Success] Task added successfully!\n");
}

void viewTasks(Task list[], int count) {
    if (count == 0) {
        printf("\n[Info] Your todo list is empty.\n");
        return;
    }
    printf("\n--- YOUR TASKS ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. [%s] %s\n", i + 1, 
               list[i].completed ? "X" : " ", 
               list[i].description);
    }
}

int main() {
    Task todoList[MAX_TASKS];
    int taskCount = 0;
    int choice;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid numeric input.\n");
            break;
        }
        switch (choice) {
            case 1:
                addTask(todoList, &taskCount);
                break;
            case 2:
                viewTasks(todoList, taskCount);
                break;
            case 3:
                printf("\nGoodbye! Cleaning up...\n");
                return 0;
            default:
                printf("\n[Error] Invalid option. Try again.\n");
        }
    }
    return 0;
}

