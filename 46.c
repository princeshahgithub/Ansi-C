#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int count_primes(int limit) {
    int count = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            count++;
        }
    }
    return count;
}

int main(void) {
    int limit = 100;
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    int total = count_primes(limit);
    printf("Total primes found: %d\n", total);
    printf("Program finished successfully.\n");
    return 0;
}

