#include <stdio.h>

int is_prime(int n)
{
    int i;

    if (n < 2)
        return (0);
    i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int main(void)
{
    int count;
    int num;

    count = 0;
    num = 2;
    printf("The first 42 prime numbers:\n");
    while (count < 42)
    {
        if (is_prime(num))
        {
            printf("%d", num);
            count++;
            if (count < 42)
                printf(", ");
            else
                printf("\n");
        }
        num++;
    }
    printf("Done!\n");
    return (0);
}

