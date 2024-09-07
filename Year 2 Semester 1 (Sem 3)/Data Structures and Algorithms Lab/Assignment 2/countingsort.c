#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sort(int *array, int size)
{
    int max = *array;
    for (int x = 0; x < size; x++)
        if (max < *(array + x))
            max = *(array + x);
    int *count = calloc(max + 1, sizeof(int));
    for (int x = 0; x < size; x++)
        (*(count + *(array + x)))++;
    for (int x = 1; x < max + 1; x++)
        *(count + x) += *(count + x - 1);
    int arrindex = 0;
    if (*count == 1)
        *(array + arrindex++) = 0;
    for (int x = 1; x < max + 1; x++)
        for (int y = 0; y < *(count + x) - *(count + x - 1); y++)
            *(array + arrindex++) = x;
    free(count);
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