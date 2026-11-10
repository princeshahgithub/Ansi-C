#include <stdio.h>
#include <stdlib.h>

void show_menu() {
    printf("\n=== 57.c CALCULATOR ===\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

int main() {
    int choice;
    double a, b, res;

    while (1) {
        show_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input type.\n");
            break;
        }

        if (choice == 5) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        if (choice >= 1 && choice <= 4) {
            printf("Enter two numbers: ");
            if (scanf("%lf %lf", &a, &b) != 2) {
                printf("Invalid number inputs.\n");
                break;
            }
        }

        switch (choice) {
            case 1: res = a + b; printf("Result: %.2lf\n", res); break;
            case 2: res = a - b; printf("Result: %.2lf\n", res); break;
            case 3: res = a * b; printf("Result: %.2lf\n", res); break;
            case 4:
                if (b != 0) {
                    res = a / b;
                    printf("Result: %.2lf\n", res);
                } else {
                    printf("Error: Division by zero!\n");
                }
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

