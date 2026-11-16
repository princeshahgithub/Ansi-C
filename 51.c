#include <stdio.h>

#define MAX_STUDENTS 5

float calculateAverage(int scores[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += scores[i];
    }
    return (float)sum / count;
}

int findHighest(int scores[], int count) {
    int max = scores[0];
    for (int i = 1; i < count; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    return max;
}

int findLowest(int scores[], int count) {
    int min = scores[0];
    for (int i = 1; i < count; i++) {
        if (scores[i] < min) {
            min = scores[i];
        }
    }
    return min;
}

int main() {
    int scores[MAX_STUDENTS];
    printf("Enter scores for %d students:\n", MAX_STUDENTS);

    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d", &scores[i]);
    }

    float avg = calculateAverage(scores, MAX_STUDENTS);
    int highest = findHighest(scores, MAX_STUDENTS);
    int lowest = findLowest(scores, MAX_STUDENTS);

    printf("\n--- Class Results ---\n");
    printf("Average Score: %.2f\n", avg);
    printf("Highest Score: %d\n", highest);
    printf("Lowest Score:  %d\n", lowest);

    return 0;
}

