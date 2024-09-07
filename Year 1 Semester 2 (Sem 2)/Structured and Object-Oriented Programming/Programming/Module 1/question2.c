// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    if (num > 0)
    {
        if (num % 2 == 0)
        {
            printf("even");
        }
        else
        {
            printf("odd");
        }
    }
    else{
        printf("Enter only positive number");
    }
}