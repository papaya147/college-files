#include <stdio.h>

int main()
{
    printf("Part 1: \n");
    int i1, i2;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &i1, &i2);
    if (i1 >= i2)
    {
        printf("The larger number is %d \n\n", i1);
    }
    else
    {
        printf("The larger number is %d \n\n", i2);
    }

    printf("Part 2: \n");
    int val;
    printf("Enter number: ");
    scanf("%d", &val);
    if (val > 0)
    {
        printf("%d is positive \n\n", val);
    }
    else
    {
        printf("\n\n");
    }

    printf("Part 3: \n");
    printf("Enter number: ");
    scanf("%d", &val);
    if (val % 2 == 0)
    {
        printf("%d is even", val);
    }
    else
    {
        printf("%d is odd", val);
    }
}