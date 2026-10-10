#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_LEN 50

struct TaskList {
    char tasks[MAX_TASKS][TASK_LEN];
    int count;
};

void showTasks(const struct TaskList *list) {
    if (list->count == 0) {
        printf("\nYour task list is currently empty.\n");
        return;
    }
    printf("\n--- Current Tasks ---\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->tasks[i]);
    }
}

void addTask(struct TaskList *list) {
    if (list->count >= MAX_TASKS) {
        printf("\nError: Task list is full!\n");
        return;
    }
    printf("\nEnter task description: ");
    getchar();
    fgets(list->tasks[list->count], TASK_LEN, stdin);
    size_t len = strlen(list->tasks[list->count]);
    if (len > 0 && list->tasks[list->count][len - 1] == '\n') {
        list->tasks[list->count][len - 1] = '\0';
    }
    list->count++;
    printf("Task added successfully!\n");
}

void removeTask(struct TaskList *list) {
    if (list->count == 0) {
        printf("\nNothing to remove.\n");
        return;
    }
    int index;
    showTasks(list);
    printf("\nEnter task number to delete: ");
    if (scanf("%d", &index) != 1 || index < 1 || index > list->count) {
        printf("Invalid task number.\n");
        return;
    }
    for (int i = index - 1; i < list->count - 1; i++) {
        strcpy(list->tasks[i], list->tasks[i + 1]);
    }
    list->count--;
    printf("Task removed successfully!\n");
}

int main(void) {
    struct TaskList myList;
    myList.count = 0;
    int choice = 0;
    while (choice != 4) {
        printf("\n=== Menu ===\n");
        printf("1. View Tasks\n");
        printf("2. Add Task\n");
        printf("3. Remove Task\n");
        printf("4. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        if (choice == 1) {
            showTasks(&myList);
        } else if (choice == 2) {
            addTask(&myList);
        } else if (choice == 3) {
            removeTask(&myList);
        }
    }
    printf("\nGoodbye!\n");
    return 0;
}

