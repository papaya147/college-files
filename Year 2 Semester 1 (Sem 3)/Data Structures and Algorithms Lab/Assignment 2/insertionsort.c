#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sort(int *arr, int size)
{
    int temp;
    for (int x = 1; x < size; x++)
        for (int y = 0; y < x; y++)
            if (*(arr + x) < *(arr + y))
            {
                temp = *(arr + x);
                for (int i = x; i >= y; i--)
                    *(arr + i) = *(arr + i - 1);
                *(arr + y) = temp;
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