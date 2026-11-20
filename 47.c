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

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(void) {
    int num;
    printf("Enter a positive integer (1-20): ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (num < 1 || num > 20) {
        printf("Number out of range.\n");
        return 1;
    }

    printf("Number: %d\n", num);
    printf("Parity: %s\n", (num % 2 == 0) ? "Even" : "Odd");

    if (is_prime(num)) {
        printf("Prime check: Yes\n");
    } else {
        printf("Prime check: No\n");
    }

    printf("Factorial: %lld\n", factorial(num));
    return 0;
}

