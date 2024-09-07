#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void merge(int *arr, int s1, int e1, int s2, int e2)
{
    int *temp = malloc((e2 - s1) * sizeof(int));
    int tempdex = 0;
    int i = s1, j = s2;
    while (i <= e1 && j <= e2)
        if (*(arr + i) < *(arr + j))
            *(temp + tempdex++) = *(arr + i++);
        else
            *(temp + tempdex++) = *(arr + j++);
    while (i <= e1)
        *(temp + tempdex++) = *(arr + i++);
    while (j <= e2)
        *(temp + tempdex++) = *(arr + j++);
    tempdex = 0;
    for (int x = s1; x <= e2; x++)
        *(arr + x) = *(temp + tempdex++);
}

void sort(int *arr, int start, int end)
{
    if (start == end)
        return;
    int mid = (start + end) / 2;
    sort(arr, start, mid);
    sort(arr, mid + 1, end);
    merge(arr, start, mid, mid + 1, end);
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