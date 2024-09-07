#include <stdio.h>
#include <stdlib.h>

struct Activity
{
    int index;
    int start;
    int end;
};

void swap(struct Activity *a1, struct Activity *a2)
{
    struct Activity temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void sort(int n, struct Activity *array)
{
    for (int x = 0; x < n - 1; x++)
    {
        int min = x;
        for (int y = x + 1; y < n; y++)
            if ((array + min)->end > (array + y)->end)
                min = y;
        swap(array + min, array + x);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Activity *array = malloc(n * sizeof(struct Activity));
    for (int x = 0; x < n; x++)
    {
        scanf("%d%d", &(array + x)->start, &(array + x)->end);
        (array + x)->index = x;
    }

    sort(n, array);

    struct Activity *soln = malloc(n * sizeof(struct Activity));
    *soln = *array;
    int start = array->end;
    int index = 0;
    for (int x = 1; x < n; x++)
        if ((array + x)->start >= start)
        {
            *(soln + ++index) = *(array + x);
            start = (array + x)->end;
        }

    printf("\n");
    for (int x = 0; x <= index; x++)
        printf("A%d\n", (soln + x)->index);

    free(array);
    free(soln);
}