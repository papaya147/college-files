#include <stdio.h>
#include <math.h>

int reverseInt(int n)
{
    int copy = n;
    int len = 0;
    int sum = 0;
    while (n != 0)
    {
        n /= 10;
        len++;
    }
    n = copy;
    for (int x = len - 1; x >= 0; x--)
    {
        printf("%d\n", pow(10, x));
        sum += (int)pow(10, x) * (int)(n % 10);
        n = n / 10;
    }
    return sum;
}

int main()
{
    int n, cop, sum = 0;
    scanf("%d", &n);
    int count = 0;
    n = reverseInt(n);
    while (n != 0)
    {
        sum += (n % 100) / 10;
        n /= 100;
    }
    printf("%d", sum);
}