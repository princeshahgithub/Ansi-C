// INT TO FLOAT NUMBER WITH HALF OF ITS VALUE 


#include<stdio.h>

int main()
{
    int x;
    printf("Enter a number : ");
    scanf("%d", &x);
    float x2 = x;
    float y = x2/2;
    printf("%f",y);
    return 0;
}