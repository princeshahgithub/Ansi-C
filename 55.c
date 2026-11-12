#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
    int id;
    char name[32];
    double value;
} Record;

void print_header(void) {
    printf("====================================\n");
    printf("      SIMPLE INVENTORY SYSTEM       \n");
    printf("====================================\n");
}

void init_records(Record list[], int count) {
    for (int i = 0; i < count; i++) {
        list[i].id = i + 1;
        snprintf(list[i].name, sizeof(list[i].name), "Item_%02d", i + 1);
        list[i].value = (i + 1) * 12.5;
    }
}

void display_records(const Record list[], int count) {
    printf("%-5s %-15s %-10s\n", "ID", "Name", "Value");
    printf("------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-15s $%-9.2f\n", list[i].id, list[i].name, list[i].value);
    }
}

double calculate_total(const Record list[], int count) {
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += list[i].value;
    }
    return total;
}

int main(void) {
    Record inventory[MAX_ITEMS];
    int count = 5;

    print_header();
    init_records(inventory, count);
    display_records(inventory, count);

    double sum = calculate_total(inventory, count);
    printf("------------------------------------\n");
    printf("Total Inventory Value: $%.2f\n", sum);
    return 0;
}

