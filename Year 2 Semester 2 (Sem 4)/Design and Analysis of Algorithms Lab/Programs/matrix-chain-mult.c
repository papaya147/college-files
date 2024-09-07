#include <stdio.h>
#include <stdlib.h>

int min(int n, int *array)
{
    int min = *array;
    for (int x = 0; x < n; x++)
        if (min > array[x])
            min = array[x];
    return min;
}

int minimiseMulti_recur(int n, int *array, int **table, int i, int j)
{
    if (i == j)
        return 0;
    if (table[i][j] != -1)
        return table[i][j];
    int *values = malloc((j - i + 1) * sizeof(int));
    for (int k = i; k < j; k++)
        values[k - i] = minimiseMulti_recur(n, array, table, i, k) +
                        minimiseMulti_recur(n, array, table, k + 1, j) +
                        array[i - 1] * array[k] * array[j];
    table[i][j] = min(j - i, values);
    free(values);
    return table[i][j];
}

int minimiseMulti(int n, int *array)
{
    int **table = malloc(n * sizeof(int *));
    for (int x = 0; x < n - 1; x++)
    {
        table[x] = malloc(n * sizeof(int));
        for (int y = 0; y < n; y++)
            table[x][y] = -1;
    }
    int min = minimiseMulti_recur(n, array, table, 1, n - 1);
    free(table);
    return min;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *array = malloc(n * sizeof(int));
    for (int x = 0; x < n; x++)
        scanf("%d", (array + x));

    int min = minimiseMulti(n, array);
    printf("%d\n", min);

    free(array);
}