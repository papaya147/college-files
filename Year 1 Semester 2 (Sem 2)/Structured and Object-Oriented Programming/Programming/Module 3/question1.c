// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *num = malloc(3 * sizeof(int));
    for (int x = 0; x < 3; x++)
        scanf("%d", num + x);
    int max = *num;
    for (int x = 0; x < 3; x++)
        if (max < *(num + x))
            max = *(num + x);
    free(num);
    printf("%d", max);
}