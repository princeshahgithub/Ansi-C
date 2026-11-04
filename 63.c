#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number;
    int user_guess;
    int attempts = 0;
    int max_attempts = 7;

    srand(time(NULL));
    secret_number = (rand() % 100) + 1;

    printf("=== Welcome to the Number Guessing Game! ===\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("Can you guess it within %d attempts?\n\n", max_attempts);

    while (attempts < max_attempts) {
        printf("Attempt %d/%d - Enter your guess: ", attempts + 1, max_attempts);
        
        if (scanf("%d", &user_guess) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        attempts++;

        if (user_guess == secret_number) {
            printf("\n🎉 Congratulations! You guessed the number in %d attempts!\n", attempts);
            return 0;
        } else if (user_guess < secret_number) {
            printf("Too low! Try a higher number.\n\n");
        } else {
            printf("Too high! Try a lower number.\n\n");
        }
    }

    printf("❌ Game Over! You've run out of attempts.\n");
    printf("The correct number was: %d\n", secret_number);

    return 0;
}
































