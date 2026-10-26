#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 7
#define MIN_NUMBER 1
#define MAX_NUMBER 72

void print_welcome() {
    printf("=================================\n");
    printf("   Welcome to the 72 Challenge!  \n");
    printf("=================================\n");
    printf("Guess the number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
    printf("You have exactly %d attempts.\n\n", MAX_ATTEMPTS);
}

int get_guess(int attempt) {
    int guess;
    printf("[Attempt %d/%d] Enter your guess: ", attempt, MAX_ATTEMPTS);
    if (scanf("%d", &guess) != 1) {
        printf("Invalid input! Please enter an integer.\n");
        while (getchar() != '\n');
        return -1;
    }
    return guess;
}

void play_game() {
    int secret_number, guess, attempts = 0;
    int won = 0;

    srand((unsigned int)time(NULL));
    secret_number = (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;

    print_welcome();

    while (attempts < MAX_ATTEMPTS) {
        guess = get_guess(attempts + 1);
        
        if (guess == -1) {
            continue;
        }

        attempts++;

        if (guess == secret_number) {
            printf("\nCongratulations! You guessed it in %d tries!\n", attempts);
            won = 1;
            break;
        } else if (guess < secret_number) {
            printf("Too low! Try a higher number.\n\n");
        } else {
            printf("Too high! Try a lower number.\n\n");
        }
    }

    if (!won) {
        printf("\nGame Over! You've run out of attempts.\n");
        printf("The correct number was: %d\n", secret_number);
    }
}

int main() {
    play_game();
    return 0;
}

