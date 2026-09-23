#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game(void) {
    int secret_number;
    int player_guess;
    int attempts = 0;
    int max_attempts = 7;

    secret_number = (rand() % 100) + 1;

    printf("\n--- NEW GAME ---\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("You have %d attempts to guess it!\n", max_attempts);

    while (attempts < max_attempts) {
        printf("\nEnter your guess: ");
        
        if (scanf("%d", &player_guess) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        attempts++;

        if (player_guess < 1 || player_guess > 100) {
            printf("Out of bounds! Guess between 1 and 100.\n");
            continue;
        }

        if (player_guess < secret_number) {
            printf("Too low! Try again.");
        } else if (player_guess > secret_number) {
            printf("Too high! Try again.");
        } else {
            printf("\nCongratulations! You got it in %d tries!\n", attempts);
            return;
        }

        printf(" (%d attempts left)\n", max_attempts - attempts);
    }

    printf("\nGame Over! You ran out of moves.\n");
    printf("The correct number was: %d\n", secret_number);
}

int main(void) {
    char choice;
    int running = 1;

    srand((unsigned int)time(NULL));

    printf("=================================\n");
    printf("   WELCOME TO THE GUESSING GAME  \n");
    printf("=================================\n");

    while (running) {
        play_game();

        printf("\nWould you like to play again? (y/n): ");
        
        while (getchar() != '\n');
        
        if (scanf("%c", &choice) != 1) {
            choice = 'n';
        }

        if (choice == 'y' || choice == 'Y') {
            running = 1;
        } else {
            running = 0;
        }
    }

    printf("\nThank you for playing! Goodbye.\n");
    return 0;
}

































