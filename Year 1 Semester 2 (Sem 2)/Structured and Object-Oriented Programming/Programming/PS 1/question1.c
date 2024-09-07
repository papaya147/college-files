// 21BDS0340 Abhinav Dinesh Srivatsa
/*
Declare integers Sum as 0 and N
Read input and assign to N
Calculate Sum as the sum of the second and fourth digit
Display Sum
*/

#include <stdio.h>

int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    sum = (n / 100) % 10 + n % 10;
    printf("%d", sum);
}