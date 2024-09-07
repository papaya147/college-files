//21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int acc[n];
    int sum = 0;
    for (int x = 0; x < n; x++)
    {
        scanf("%d", &acc[x]);
        sum += acc[x];
    }
    int mean = sum / n;
    for (int x = 0; x < n; x++)
    {
        acc[x] = abs(mean - acc[x]);
        printf("%d\n", acc[x]);
    }
}