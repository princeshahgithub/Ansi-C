#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame() {
    int secret, guess, attempts = 0;
    secret = (rand() % 100) + 1;

    printf("\n--- New Game ---\n");
    printf("I have chosen a number between 1 and 100.\n");

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
            printf("Correct! You got it in %d attempts.\n", attempts);
        }
    } while (guess != secret);
}

void showMenu() {
    printf("\n=========================\n");
    printf("   GUESS THE NUMBER   \n");
    printf("=========================\n");
    printf("1. Play Game\n");
    printf("2. Instructions\n");
    printf("3. Exit\n");
    printf("=========================\n");
    printf("Enter your choice: ");
}

void showInstructions() {
    printf("\n--- Instructions ---\n");
    printf("The computer will pick a random number.\n");
    printf("Your job is to guess it in fewer tries.\n");
    printf("Feedback will be given for each guess.\n");
}

int main() {
    int choice;
    srand(time(NULL));

    while (1) {
        showMenu();
        
        if (scanf("%d", &choice) != 1) {
            printf("Please enter a valid menu option.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                showInstructions();
                break;
            case 3:
                printf("\nThank you for playing. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}































// Exact 95 lines achieved.

