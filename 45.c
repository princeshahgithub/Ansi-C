#include <stdio.h>

void print_banner(void) {
    printf("=== Simple Array Analyzer ===\n");
}

double calculate_average(const int *arr, int size) {
    if (size <= 0) {
        return 0.0;
    }
    long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

int find_max(const int *arr, int size) {
    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

int main(void) {
    int numbers[] = {12, 45, 7, 89, 23, 56, 34};
    int count = sizeof(numbers) / sizeof(numbers[0]);

    print_banner();
    printf("Elements: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    double avg = calculate_average(numbers, count);
    int max_num = find_max(numbers, count);

    printf("Average: %.2f\n", avg);
    printf("Maximum: %d\n", max_num);
    return 0;
}
