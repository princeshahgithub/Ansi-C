#include <stdio.h>

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int limit = 30;
    int count = 0;

    printf("Prime numbers up to %d:\n", limit);

    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
            count++;
        }
    }

    printf("\n\nTotal primes found: %d\n", count);

    if (count > 5) {
        printf("That is a good collection of primes.\n");
    } else if (count > 0) {
        printf("That is a small collection of primes.\n");
    } else {
        printf("No primes were found.\n");
    }

    printf("Program finished successfully.\n");

    return 0;
}

