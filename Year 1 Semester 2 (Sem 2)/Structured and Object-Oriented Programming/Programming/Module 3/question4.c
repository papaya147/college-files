// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    char date[10];
    int *rain = calloc(12, sizeof(int));
    int cm;
    char month[3];
    for (int x = 0; x < n; x++)
    {
        scanf("%s", date);
        scanf("%d", &cm);
        strncpy(month, &date[3], 2);
        rain[atoi(month) - 1] += cm;
    }
    int sum = 0;
    for (int x = 0; x < 12; x++)
    {
        if (*(rain + x) != 0)
        {
            printf("%d\n%d\n", (x + 1), *(rain + x));
            sum += *(rain + x);
        }
    }
    printf("%d", (int)round((float)sum / n));
    free(rain);
}