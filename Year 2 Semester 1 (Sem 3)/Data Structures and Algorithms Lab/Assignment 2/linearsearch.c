#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int search(int *arr, int size, int n)
{
    int pos = -1;
    for (int x = 0; x < size; x++)
        if (*(arr + x) == n)
            return x;
    return pos;
}

int main()
{
    bool flag = false;
    int *arr, size, n;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    arr = malloc(size * sizeof(int));
    for (int x = 0; x < size; x++)
        scanf("%d", arr + x);
    printf("Enter element to search for: ");
    scanf("%d", &n);
    int pos = search(arr, size, n);
    if (pos == -1)
        printf("Element not found.");
    else
        printf("Element found at position %d.", pos + 1);
    free(arr);
}