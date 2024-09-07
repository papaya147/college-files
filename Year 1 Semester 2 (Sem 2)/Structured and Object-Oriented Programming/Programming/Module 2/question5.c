// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>
#include <stdlib.h>

void read_Count(int *array, int n)
{
    for (int x = 0; x < n; x++)
    {
        scanf("%d", &array[x]);
    }
}

float find_Mean(int *array, int n)
{
    float sum = 0;
    for (int x = 0; x < n; x++)
    {
        sum += array[x];
    }
    return sum / n;
}

void print_Diff(int *array, int n, float mean)
{
    for (int x = 0; x < n; x++)
    {
        printf("%d\n", abs((int)mean - array[x]));
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int acc[n];
    read_Count(acc, n);
    float mean = find_Mean(acc, n);
    print_Diff(acc, n, mean);
}