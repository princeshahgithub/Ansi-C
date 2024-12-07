// Example : Take two integers input, a and b : a>b,
//and find the remainder when a is divided by b amd print the remainder.

// (Divisor * Quotient + Remainder = Dividend)

#include<stdio.h>

int main()
{
    int a,b,q,r;
    printf("Enter the first number : ");
    scanf("%d",&a);
    printf("Enter the second number : ");
    scanf("%d",&b);
    q=a/b;
    printf("Quotient : %d\n",q);

    if(a>b)
    {
        r=a-(b*q);
        printf("Remainder : %d\n",r);
    }

    else
    {
        printf("Invalid Input");
    }

    return 0;


}


