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
    int limit, count = 0;

    printf("Enter an upper limit: ");
    if (scanf("%d", &limit) != 1 || limit < 2) {
        printf("Please enter an integer >= 2.\n");
        return 1;
    }

    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
            if (count % 10 == 0) {
                printf("\n");
            }
        }
    }

    if (count % 10 != 0) {
        printf("\n");
    }
    printf("Total primes found: %d\n", count);
    return 0;
}

