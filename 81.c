#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 5
#define NAME_LEN 32

struct Item {
    char name[NAME_LEN];
    int quantity;
    double unit_price;
};

void print_header() {
    printf("\n==================================\n");
    printf("   INVENTORY MANAGEMENT SYSTEM   \n");
    printf("==================================\n");
}

void print_item(const struct Item *item, int index) {
    printf("%d. %-15s | Qty: %-3d | Price: $%-7.2f\n", 
           index + 1, item->name, item->quantity, item->unit_price);
}

int main() {
    struct Item inventory[MAX_ITEMS];
    int current_count = 0;
    int choice;
    double grand_total;

    while (1) {
        print_header();
        printf("1. Add New Item\n");
        printf("2. View Current Inventory\n");
        printf("3. Calculate Total Asset Value\n");
        printf("4. Exit System\n");
        printf("Enter option (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid system input stream execution.\n");
            break;
        }

        if (choice == 4) {
            printf("Exiting inventory management terminal safely.\n");
            break;
        }

        switch (choice) {
            case 1:
                if (current_count >= MAX_ITEMS) {
                    printf("Error: Inventory storage limit reached!\n");
                    break;
                }
                printf("Enter item label: ");
                scanf("%31s", inventory[current_count].name);
                printf("Enter stock quantity: ");
                scanf("%d", &inventory[current_count].quantity);
                printf("Enter unit price: ");
                scanf("%lf", &inventory[current_count].unit_price);
                current_count++;
                printf("Asset successfully committed to registry.\n");
                break;

            case 2:
                if (current_count == 0) {
                    printf("Notice: Registry is currently empty.\n");
                    break;
                }
                for (int i = 0; i < current_count; i++) {
                    print_item(&inventory[i], i);
                }
                break;

            case 3:
                grand_total = 0.0;
                for (int i = 0; i < current_count; i++) {
                    grand_total += inventory[i].quantity * inventory[i].unit_price;
                }
                printf("Cumulative Asset Appraisal: $%.2f\n", grand_total);
                break;

            default:
                printf("Warning: Command option outside valid bounds.\n");
        }
    }
    return 0;
}

