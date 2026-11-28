#include <stdio.h>

int main(void) {
    int limit = 10;
    int sum = 0;

    printf("Numbers from 1 to %d:\n", limit);

    for (int i = 1; i <= limit; i++) {
        printf("%d ", i);
        sum += i;
    }

    printf("\n\nTotal sum: %d\n", sum);

    if (sum > 50) {
        printf("Sum is greater than 50.\n");
    } else {
        printf("Sum is 50 or less.\n");
    }

    int even_count = 0;
    for (int i = 1; i <= limit; i++) {
        if (i % 2 == 0) {
            even_count++;
        }
    }

    printf("Even numbers count: %d\n", even_count);

    printf("Processing steps:\n");
    for (int i = 1; i <= 3; i++) {
        printf("Step %d complete.\n", i);
    }

    printf("Program finished successfully.\n");

    return 0;
}

