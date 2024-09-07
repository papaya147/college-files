// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>

int main()
{
    int n;
    int flag = 0;
    scanf("%d", &n);
    int x = 2;
    while (x < n / 2)
    {
        if (n % x == 0)
        {
            printf("Not Prime");
            flag = 1;
            break;
        }
        x++;
    }
    if (flag == 0)
    {
        printf("Prime");
    }
}