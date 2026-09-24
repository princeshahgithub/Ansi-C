#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
}

// Function to print a separator line
void print_separator(char c, int width) {
    for (int i = 0; i < width; i++) {
        putchar(c);
    }
    putchar('\n');
}

// Main function executing the logic
int main(void) {
    int max_limit = 97;
    int prime_count = 0;

    print_separator('=', 40);
    printf("Welcome to the 97-Line C Program!\n");
    printf("Target limit set to: %d\n", max_limit);
    print_separator('=', 40);

    printf("\nFinding all prime numbers up to %d:\n", max_limit);
    print_separator('-', 40);

    for (int i = 2; i <= max_limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            prime_count++;
            
            if (prime_count % 5 == 0) {
                printf("\n");
            }
        }
    }

    printf("\n\n");
    print_separator('-', 40);
    printf("Total prime numbers found: %d\n", prime_count);
    print_separator('=', 40);

    printf("ASCII character for %d is: '%c'\n", max_limit, (char)max_limit);
    
    printf("Demonstrating a simple countdown loop:\n");
    for (int down = 5; down > 0; down--) {
        printf("  T-minus %d...\n", down);
    }

    printf("\nProgram complete. Exiting successfully.\n");
    print_separator('=', 40);

    return 0;
}

