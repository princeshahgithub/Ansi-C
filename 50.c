#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 5

typedef struct {
    int id;
    char title[50];
    int completed;
} Task;

void print_menu(void) {
    printf("\n--- Task Manager ---\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Mark Completed\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void view_tasks(Task tasks[], int count) {
    printf("\nYour Tasks:\n");
    for (int i = 0; i < count; i++) {
        printf("[%d] %s - %s\n", tasks[i].id, tasks[i].title,
               tasks[i].completed ? "Done" : "Pending");
    }
}

int main(void) {
    Task tasks[MAX_TASKS];
    int count = 0, choice = 0;

    while (choice != 4) {
        print_menu();
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1 && count < MAX_TASKS) {
            tasks[count].id = count + 1;
            tasks[count].completed = 0;
            printf("Enter single-word title: ");
            scanf("%49s", tasks[count].title);
            count++;
        } else if (choice == 2) {
            view_tasks(tasks, count);
        } else if (choice == 3 && count > 0) {
            tasks[count - 1].completed = 1;
            printf("Latest task marked done.\n");
        }
    }
    return 0;
}
