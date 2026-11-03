#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 10
#define BUFFER_SIZE 64

typedef struct {
    int id;
    char name[BUFFER_SIZE];
    double price;
} Item;

void print_header(const char *title) {
    printf("\n=== %s ===\n", title);
}

int generate_id(void) {
    return (rand() % 9000) + 1000;
}

void display_item(const Item *item) {
    if (item == NULL) return;
    printf("ID: %d | Name: %s | Price: $%.2f\n", 
           item->id, item->name, item->price);
}

int main(void) {
    Item inventory[MAX_ITEMS];
    int item_count = 0;
    
    srand((unsigned int)time(NULL));
    print_header("Inventory System Initialized");
    
    const char *sample_names[] = {"Laptop", "Phone", "Tablet", "Watch"};
    double sample_prices[] = {999.99, 699.49, 399.99, 199.95};
    int sample_count = 4;

    for (int i = 0; i < sample_count && item_count < MAX_ITEMS; i++) {
        inventory[item_count].id = generate_id();
        strncpy(inventory[item_count].name, sample_names[i], BUFFER_SIZE - 1);
        inventory[item_count].name[BUFFER_SIZE - 1] = '\0';
        inventory[item_count].price = sample_prices[i];
        item_count++;
    }

    print_header("Current Stock");
    double total_value = 0.0;
    
    for (int i = 0; i < item_count; i++) {
        display_item(&inventory[i]);
        total_value += inventory[i].price;
    }

    printf("-----------------------------------\n");
    printf("Total Items: %d\n", item_count);
    printf("Total Inventory Value: $%.2f\n", total_value);
    print_header("System Shutdown");

    return EXIT_SUCCESS;
}

