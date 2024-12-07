
// HW: Any year is input through the keyboard. Write
// a program to determine whether the year is a leap
// year or not. (Considering leap year occurs after
// every 4 years)


#include <stdio.h>

int main() {
    int year;

    // Input year from the user
    printf("Enter a year: ");
    scanf("%d", &year);

    // Check if the year is a leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}