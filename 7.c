// Volume Of Sphere In C


#include <stdio.h>


int main() {
    int radius;
    float volume;

    // Prompt user for the radius
    printf("Enter the radius of the sphere: ");
    scanf("%d", &radius);

    // Calculate the volume
    volume = (4.0 / 3.0) * 3.14 * radius * radius * radius;

    // Display the result
    printf("The volume of the sphere with radius %d is: %f\n", radius, volume);

    return 0;
}

