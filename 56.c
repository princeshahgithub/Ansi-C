#include <stdio.h>
#include <stdbool.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    char title[50];
    bool completed;
} Task;

void print_menu(void) {
    printf("\n1. Add Task\n2. View Tasks\n3. Complete Task\n4. Exit\nChoice: ");
}

void add_task(Task tasks[], int *count) {
    if (*count >= MAX_TASKS) {
        printf("Task list is full.\n");
        return;
    }
    tasks[*count].id = *count + 1;
    printf("Enter task title: ");
    scanf(" %49[^\n]", tasks[*count].title);
    tasks[*count].completed = false;
    (*count)++;
}

void view_tasks(const Task tasks[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. [%c] %s\n", tasks[i].id, tasks[i].completed ? 'X' : ' ', tasks[i].title);
    }
}

void complete_task(Task tasks[], int count) {
    int id;
    printf("Enter task ID: ");
    if (scanf("%d", &id) == 1 && id >= 1 && id <= count) {
        tasks[id - 1].completed = true;
    } else {
        printf("Invalid ID.\n");
    }
}

int main(void) {
    Task tasks[MAX_TASKS];
    int count = 0, choice;
    while (true) {
        print_menu();
        if (scanf("%d", &choice) != 1 || choice == 4) break;
        if (choice == 1) add_task(tasks, &count);
        else if (choice == 2) view_tasks(tasks, count);
        else if (choice == 3) complete_task(tasks, count);
        else printf("Invalid choice.\n");
    }
    return 0;
}
