#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int search(int *arr, int start, int end, int n)
{
    int mid = (start + end) / 2;
    if (start == end)
        return -1;
    if (*(arr + mid) == n)
        return mid;
    else if (*(arr + mid) > n)
        search(arr, start, mid, n);
    else
        search(arr, mid, end, n);
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
    int pos = search(arr, 0, size, n);
    if (pos == -1)
        printf("Element not found.");
    else
        printf("Element found at position %d.", pos + 1);
    free(arr);
}