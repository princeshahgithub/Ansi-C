#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame() {
    int secret, guess, attempts = 0;
    secret = (rand() % 100) + 1;

    printf("\n--- New Game ---\n");
    printf("I've chosen a number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        attempts++;

        if (guess > secret) {
            printf("Too high! Try again.\n");
        } else if (guess < secret) {
            printf("Too low! Try again.\n");
        } else {
            printf("Correct! You got it in %d tries.\n", attempts);
        }
    } while (guess != secret);
}

int main() {
    int choice;
    srand(time(NULL));

    printf("=================================\n");
    printf("   Welcome to the Guessing Game  \n");
    printf("=================================\n");

    while (1) {
        printf("\n1. Play Game\n");
        printf("2. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 1) {
            playGame();
        } else if (choice == 2) {
            printf("Thanks for playing! Goodbye.\n");
            break;
        } else {
            printf("Please select option 1 or 2.\n");
        }
    }

    return 0;
}

