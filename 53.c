#include <stdio.h>
#include <string.h>

#define MAX_TASKS 5
#define MAX_LEN 50

typedef struct {
    int id;
    char title[MAX_LEN];
    int completed;
} Task;

void print_header(void) {
    printf("==========================\n");
    printf("   DAILY TASK TRACKER     \n");
    printf("==========================\n");
}

void add_task(Task tasks[], int *count, const char *title) {
    if (*count < MAX_TASKS) {
        tasks[*count].id = *count + 1;
        strncpy(tasks[*count].title, title, MAX_LEN - 1);
        tasks[*count].title[MAX_LEN - 1] = '\0';
        tasks[*count].completed = 0;
        (*count)++;
    }
}

void complete_task(Task tasks[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (tasks[i].id == id) {
            tasks[i].completed = 1;
        }
    }
}

void display_tasks(const Task tasks[], int count) {
    for (int i = 0; i < count; i++) {
        const char *status = tasks[i].completed ? "DONE" : "TODO";
        printf("[%s] %d. %s\n", status, tasks[i].id, tasks[i].title);
    }
}

int main(void) {
    Task list[MAX_TASKS];
    int task_count = 0;
    print_header();
    add_task(list, &task_count, "Write C program");
    add_task(list, &task_count, "Verify line count");
    add_task(list, &task_count, "Compile and run");
    complete_task(list, task_count, 1);
    display_tasks(list, task_count);
    return 0;
}

