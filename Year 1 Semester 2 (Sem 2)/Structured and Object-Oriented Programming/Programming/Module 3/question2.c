// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int x = 0; x < n; x++)
        scanf("%d", (arr + x));
    for (int x = n - 1; x > -1; x--)
        printf("%d\n", *(arr + x));
    free(arr);
}