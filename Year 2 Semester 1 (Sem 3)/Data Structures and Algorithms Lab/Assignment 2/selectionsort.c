#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int *arr, int size)
{
    int mindex;
    for (int i = 0; i < size; i++)
    {
        mindex = i;
        for (int x = i; x < size; x++)
            if (*(arr + mindex) > *(arr + x))
                mindex = x;
        swap(arr + mindex, arr + i);
    }
}

int main()
{
    int *arr, size;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    arr = malloc(sizeof(int) * size);
    for (int x = 0; x < size; x++)
        scanf("%d", arr + x);
    sort(arr, size);
    for (int x = 0; x < size; x++)
        printf("%d ", *(arr + x));
    free(arr);
}