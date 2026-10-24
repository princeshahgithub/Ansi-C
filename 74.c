#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game(void) {
    int secret_number;
    int player_guess;
    int attempts = 0;
    const int max_attempts = 10;

    secret_number = (rand() % 100) + 1;

    printf("\n=== NEW GAME ===\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("You have %d attempts to guess it!\n", max_attempts);

    while (attempts < max_attempts) {
        printf("\nAttempt %d/%d. Enter your guess: ", attempts + 1, max_attempts);
        
        if (scanf("%d", &player_guess) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            while (getchar() != '\n'); 
            continue;
        }

        attempts++;

        if (player_guess == secret_number) {
            printf("Congratulations! You guessed it in %d attempts!\n", attempts);
            return;
        } else if (player_guess < secret_number) {
            printf("Too low! Try a higher number.\n");
        } else {
            printf("Too high! Try a lower number.\n");
        }
    }

    printf("\nGame Over! You ran out of attempts.\n");
    printf("The correct number was: %d\n", secret_number);
}

int main(void) {
    int choice;

    srand((unsigned int)time(NULL));

    printf("=================================\n");
    printf("   WELCOME TO THE GUESSING GAME  \n");
    printf("=================================\n");

    do {
        printf("\nMenu:\n");
        printf("1. Play Game\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Exiting program.\n");
            break;
        }

        if (choice == 1) {
            play_game();
        } else if (choice != 2) {
            printf("Unknown option. Please try again.\n");
        }

    } while (choice != 2);

    printf("\nThank you for playing! Goodbye.\n");
    return 0;
}

