// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>
#include <stdlib.h>

int findMin_21BDS0340(int *arr)
{
    int min = *arr;
    for (int x = 0; x < 5; x++)
        if (min > *(arr + x))
            min = *(arr + x);
    return min;
}

int findMax_21BDS0340(int *arr)
{
    int max = *arr;
    for (int x = 0; x < 5; x++)
        if (max < *(arr + x))
            max = *(arr + x);
    return max;
}

int main()
{
    int *arr = malloc(5 * sizeof(int));
    for (int x = 0; x < 5; x++)
        scanf("%d", arr + x);
    printf("%d\n%d", findMax_21BDS0340(arr), findMin_21BDS0340(arr));
    free(arr);
}