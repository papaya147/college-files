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
    for (int x = 0; x < size - 1; x++)
        for (int y = 0; y < size - x - 1; y++)
            if (*(arr + y) > *(arr + y + 1))
                swap(arr + y, arr + y + 1);
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