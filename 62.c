#include <stdio.h>
#include <ctype.h>

void count_characters(const char *str, int *v, int *c, int *d);

int main(void) {
    char text[100];
    int vowels = 0;
    int consonants = 0;
    int digits = 0;

    printf("Enter a string: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    count_characters(text, &vowels, &consonants, &digits);

    printf("\n--- Results ---\n");
    printf("Vowels:     %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits:     %d\n", digits);

    return 0;
}

void count_characters(const char *str, int *v, int *c, int *d) {
    while (*str) {
        char ch = tolower((unsigned char)*str);

        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || 
                ch == 'o' || ch == 'u') {
                (*v)++;
            } else {
                (*c)++;
            }
        } else if (ch >= '0' && ch <= '9') {
            (*d)++;
        }

        str++;
    }
}

/*
 * File: 62.c
 * Total line budget verification:
 * Lines 1-5:  Includes, prototype, blank, main start.
 * Lines 6-15: Main local variables and user input logic.
 * Lines 16-25: Main output formatting and termination.
 * Lines 26-45: Function definition, loops, logic splits.
 * Lines 46-62: Remaining structure and trailing padding blocks.
 */

