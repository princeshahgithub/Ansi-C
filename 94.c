#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 50
#define TASK_LEN 64

typedef struct {
    char description[TASK_LEN];
    int completed;
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int count;
} TodoList;

void print_header(void) {
    printf("\n=================================\n");
    printf("        SIMPLE TODO LIST         \n");
    printf("=================================\n");
}

void show_tasks(const TodoList *list) {
    if (list->count == 0) {
        printf("\nYour todo list is empty!\n");
        return;
    }
    printf("\nYour Current Tasks:\n");
    for (int i = 0; i < list->count; i++) {
        printf("[%c] %d. %s\n", 
               list->tasks[i].completed ? 'X' : ' ', 
               i + 1, 
               list->tasks[i].description);
    }
}

void add_task(TodoList *list) {
    if (list->count >= MAX_TASKS) {
        printf("\nError: Todo list is completely full!\n");
        return;
    }
    printf("\nEnter task description: ");
    getchar(); 
    fgets(list->tasks[list->count].description, TASK_LEN, stdin);
    list->tasks[list->count].description[strcspn(list->tasks[list->count].description, "\n")] = 0;
    list->tasks[list->count].completed = 0;
    list->count++;
    printf("Task added successfully!\n");
}

void complete_task(TodoList *list) {
    int index;
    if (list->count == 0) {
        printf("\nNo tasks available to complete.\n");
        return;
    }
    printf("\nEnter task number to complete: ");
    if (scanf("%d", &index) != 1 || index < 1 || index > list->count) {
        printf("Invalid task number selector.\n");
        return;
    }
    list->tasks[index - 1].completed = 1;
    printf("Task marked as completed!\n");
}

int main(void) {
    TodoList my_list = { .count = 0 };
    int choice;

    while (1) {
        print_header();
        printf("1. View All Tasks\n");
        printf("2. Add New Task\n");
        printf("3. Complete a Task\n");
        printf("4. Exit Application\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        if (choice == 4) {
            printf("\nGoodbye! Have a productive day.\n");
            break;
        }

        switch (choice) {
            case 1: show_tasks(&my_list); break;
            case 2: add_task(&my_list); break;
            case 3: complete_task(&my_list); break;
            default: printf("\nInvalid option. Try again.\n");
        }
    }
    return 0;
}

