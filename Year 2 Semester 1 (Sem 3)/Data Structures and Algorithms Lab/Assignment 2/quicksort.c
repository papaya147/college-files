#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int *arr, int left, int right)
{
    int start = left, end = right;
    int pivot = left;
    if (left >= right)
        return;
    while (left < right)
    {
        if (*(arr + left) > *(arr + right))
        {
            swap(arr + left, arr + right);
            if (pivot == left)
                pivot = right;
            else
                pivot = left;
        }
        if (pivot == left)
            right--;
        else
            left++;
    }
    sort(arr, start, pivot - 1);
    sort(arr, pivot + 1, end);
}

int main()
{
    int *arr, size;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    arr = malloc(sizeof(int) * size);
    for (int x = 0; x < size; x++)
        scanf("%d", arr + x);
    sort(arr, 0, size - 1);
    for (int x = 0; x < size; x++)
        printf("%d ", *(arr + x));
    free(arr);
}