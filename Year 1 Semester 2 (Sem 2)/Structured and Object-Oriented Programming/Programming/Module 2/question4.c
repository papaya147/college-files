// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>

void swap_twoNumbers(int *i1, int *i2)
{
    int temp = *i2;
    *i2 = *i1;
    *i1 = temp;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    swap_twoNumbers(&a, &b);
    printf("%d\n%d", a, b);
}