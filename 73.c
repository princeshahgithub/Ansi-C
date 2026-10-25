#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_LEN 50

void displayMenu() {
    printf("\n--- TASK MANAGER ---\n");
    printf("1. Add a Task\n");
    printf("2. View All Tasks\n");
    printf("3. Exit Program\n");
    printf("Enter choice (1-3): ");
}

void addTask(char list[MAX_TASKS][TASK_LEN], int *count) {
    if (*count >= MAX_TASKS) {
        printf("\n[Error] Your task list is completely full!\n");
        return;
    }
    printf("Enter the new task description: ");
    getchar();
    fgets(list[*count], TASK_LEN, stdin);
    list[*count][strcspn(list[*count], "\n")] = '\0';
    (*count)++;
    printf("[Success] Task added successfully.\n");
}

void viewTasks(char list[MAX_TASKS][TASK_LEN], int count) {
    if (count == 0) {
        printf("\n[Info] Your task list is currently empty.\n");
        return;
    }
    printf("\n--- CURRENT TASKS ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, list[i]);
    }
}

int main() {
    char tasks[MAX_TASKS][TASK_LEN];
    int taskCount = 0;
    int choice = 0;

    while (choice != 3) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("[Error] Invalid numeric input received.\n");
            break;
        }
        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("[Warning] Invalid choice. Try again.\n");
        }
    }
    return 0;
}

