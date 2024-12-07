// FLOAT TO INT FOR FINDING NUMBER AFTER THE DECIMAL POINT


#include <stdio.h>

int main() {
    float x = 5.7;
    int y = (int)x; // Cast float to int to get the integer part
    printf("%d\n", y); // Print the integer part
    
    float z = x - y; // Calculate the decimal part
    printf("%f\n", z); // Print the decimal part

    return 0;
}