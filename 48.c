/* 48.c - Number Parity Analyzer */
#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10

int is_even(int num) {
    return num % 2 == 0;
}

void print_header(void) {
    printf("=== Number Parity Checker ===\n");
}

void process_numbers(int limit) {
    int i;
    int even_count = 0;
    int odd_count = 0;

    for (i = 1; i <= limit; i++) {
        if (is_even(i)) {
            printf("%2d is even\n", i);
            even_count++;
        } else {
            printf("%2d is odd\n", i);
            odd_count++;
        }
    }

    printf("\nSummary:\n");
    printf("Total numbers: %d\n", limit);
    printf("Even count:    %d\n", even_count);
    printf("Odd count:     %d\n", odd_count);
}

void print_footer(void) {
    printf("=============================\n");
}

int main(void) {
    int limit = LIMIT;

    print_header();
    process_numbers(limit);
    print_footer();

    return EXIT_SUCCESS;
}

