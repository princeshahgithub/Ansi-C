#include <stdio.h>

int main() {
    float m1, m2, m3, m4, m5; // Declare variables for the marks of 5 subjects
    float percentage; // Variable to store the calculated percentage

    // Input scores for each subject
    printf("Enter Value Of m1 (out of 40): ");
    scanf("%f", &m1);
    
    printf("Enter Value Of m2 (out of 40): ");
    scanf("%f", &m2);
    
    printf("Enter Value Of m3 (out of 40): ");
    scanf("%f", &m3);
    
    printf("Enter Value Of m4 (out of 40): ");
    scanf("%f", &m4);
    
    printf("Enter Value Of m5 (out of 40): ");
    scanf("%f", &m5);
    
    // Calculate total marks obtained
    float total = m1 + m2 + m3 + m4 + m5;

    // Calculate percentage
    percentage = (total / (5 * 40)) * 100; // Total possible marks is 5 * 40 = 200

    // Print the result
    printf("Total Marks Obtained: %.2f out of 200\n", total);
    printf("Percentage of 5 subjects is: %.2f%%\n", percentage); // Print with two decimal places

    return 0;
}
