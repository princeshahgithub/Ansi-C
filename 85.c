#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 50
#define TASK_LEN 100
#define FILE_NAME "todo.txt"

void show_tasks() {
    char task[TASK_LEN];
    FILE *f = fopen(FILE_NAME, "r");
    if (!f) {
        printf("\nNo tasks found. Add some!\n");
        return;
    }
    printf("\n--- Current To-Do List ---\n");
    int i = 1;
    while (fgets(task, sizeof(task), f)) {
        task[strcspn(task, "\n")] = 0;
        printf("%d. %s\n", i++, task);
    }
    fclose(f);
}

void add_task() {
    char task[TASK_LEN];
    printf("\nEnter task details: ");
    getchar();
    fgets(task, sizeof(task), stdin);
    FILE *f = fopen(FILE_NAME, "a");
    if (f) {
        fputs(task, f);
        fclose(f);
        printf("Task added successfully!\n");
    }
}

void clear_tasks() {
    FILE *f = fopen(FILE_NAME, "w");
    if (f) {
        fclose(f);
        printf("\nAll tasks cleared!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n=== TODO MANAGER ===\n");
        printf("1. View Tasks\n");
        printf("2. Add Task\n");
        printf("3. Clear All\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        switch (choice) {
            case 1:
                show_tasks();
                break;
            case 2:
                add_task();
                break;
            case 3:
                clear_tasks();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}

