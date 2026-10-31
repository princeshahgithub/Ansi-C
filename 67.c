#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game() {
    int secret_number;
    int guess;
    int attempts = 0;
    
    secret_number = (rand() % 100) + 1;
    
    printf("\n--- Guess the Number Game ---\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("Can you guess what it is?\n\n");
    
    do {
        printf("Enter your guess: ");
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            while (getchar() != '\n'); 
            continue;
        }
        
        attempts++;
        
        if (guess > secret_number) {
            printf("Too high! Try again.\n");
        } else if (guess < secret_number) {
            printf("Too low! Try again.\n");
        } else {
            printf("\nCorrect! You found it in %d attempts.\n", attempts);
        }
    } while (guess != secret_number);
}

int main() {
    int choice;
    srand(time(NULL));
    
    printf("Welcome to the 67-Line C Program!\n");
    
    while (1) {
        printf("\n1. Play Guessing Game\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection.\n");
            while (getchar() != '\n');
            continue;
        }
        
        if (choice == 1) {
            play_game();
        } else if (choice == 2) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid option. Choose 1 or 2.\n");
        }
    }
    
    return 0;
}

