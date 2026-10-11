#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_LEN 50

typedef struct {
    char description[TASK_LEN];
    int completed;
} Task;

void show_tasks(const Task *tasks, int count) {
    printf("\n--- Current Todo List ---\n");
    if (count == 0) {
        printf("No tasks yet! Add some below.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("[%c] %d. %s\n", tasks[i].completed ? 'X' : ' ', i + 1, tasks[i].description);
    }
}

int main(void) {
    Task tasks[MAX_TASKS];
    int task_count = 0;
    int choice;
    char buffer[TASK_LEN];

    printf("Welcome to your 86-line C Todo App!\n");

    while (1) {
        show_tasks(tasks, task_count);
        printf("\nOptions:\n1. Add Task\n2. Toggle Complete\n3. Exit\n");
        printf("Enter choice (1-3): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        getchar(); 

        if (choice == 1) {
            if (task_count >= MAX_TASKS) {
                printf("List is full! Clear some tasks first.\n");
                continue;
            }
            printf("Enter task description: ");
            if (fgets(buffer, TASK_LEN, stdin)) {
                buffer[strcspn(buffer, "\n")] = '\0';
                strncpy(tasks[task_count].description, buffer, TASK_LEN);
                tasks[task_count].completed = 0;
                task_count++;
                printf("Task added successfully!\n");
            }
        } else if (choice == 2) {
            if (task_count == 0) {
                printf("No tasks to modify.\n");
                continue;
            }
            int index;
            printf("Enter task number to toggle: ");
            if (scanf("%d", &index) == 1 && index >= 1 && index <= task_count) {
                tasks[index - 1].completed = !tasks[index - 1].completed;
                printf("Task status updated!\n");
            } else {
                printf("Invalid task number.\n");
            }
            getchar(); 
        } else if (choice == 3) {
            printf("Goodbye! Thanks for staying organized.\n");
            break;
        } else {
            printf("Invalid choice. Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}

