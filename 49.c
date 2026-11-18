#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void initializeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (i + 1) * 10;
    }
}

void printArray(const int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int calculateSum(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int findMax(const int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main(void) {
    int numbers[ARRAY_SIZE];
    initializeArray(numbers, ARRAY_SIZE);
    printArray(numbers, ARRAY_SIZE);

    int total = calculateSum(numbers, ARRAY_SIZE);
    int maximum = findMax(numbers, ARRAY_SIZE);

    printf("Total sum: %d\n", total);
    printf("Maximum value: %d\n", maximum);
    return 0;
}
