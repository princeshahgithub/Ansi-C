#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame() {
    int secret, guess, attempts = 0;
    secret = (rand() % 100) + 1;

    printf("\n--- Guess the Number (1-100) ---\n");

    do {
        printf("Enter your guess: ");
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        attempts++;

        if (guess > secret) {
            printf("Too high! Try again.\n");
        } else if (guess < secret) {
            printf("Too low! Try again.\n");
        } else {
            printf("\nCongratulations! You got it!\n");
            printf("It took you %d attempts.\n", attempts);
        }
    } while (guess != secret);
}

void showMenu() {
    printf("=================================\n");
    printf("     MINI C GUESSING GAME        \n");
    printf("=================================\n");
    printf("1. Play Game\n");
    printf("2. Exit\n");
    printf("Enter choice: ");
}

int main() {
    int choice;
    srand((unsigned int)time(NULL));

    while (1) {
        showMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Exiting.\n");
            break;
        }

        if (choice == 1) {
            playGame();
            printf("\nReady for another round?\n\n");
        } else if (choice == 2) {
            printf("Thanks for playing! Goodbye.\n");
            break;
        } else {
            printf("Invalid option. Try again.\n\n");
        }
    }

    return 0;
}

