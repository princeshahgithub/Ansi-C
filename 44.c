#include <stdio.h>
#include <stdlib.h>

#define LIMIT 44

int is_prime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void print_primes(int max) {
    int count = 0;
    printf("Prime numbers up to %d:\n", max);
    for (int i = 2; i <= max; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal primes found: %d\n", count);
}

int main(void) {
    int target = LIMIT;
    printf("Starting 44.c execution...\n");

    if (target <= 0) {
        fprintf(stderr, "Error: Invalid limit.\n");
        return EXIT_FAILURE;
    }

    print_primes(target);
    printf("Execution completed successfully.\n");
    printf("Done.\n");

    return EXIT_SUCCESS;
}
