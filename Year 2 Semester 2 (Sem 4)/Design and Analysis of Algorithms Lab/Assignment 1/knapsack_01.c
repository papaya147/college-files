#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int weight;
    int value;
};

int max(int a, int b)
{
    return a > b ? a : b;
}

void swap(struct Item *a1, struct Item *a2)
{
    struct Item temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void sort(int n, struct Item *item)
{
    for (int x = 0; x < n - 1; x++)
    {
        int min = x;
        for (int y = x + 1; y < n; y++)
            if ((item + min)->weight > (item + y)->weight)
                min = y;
        swap(item + min, item + x);
    }
}

int knapsack_recur(int w, struct Item *item, int i, int **table)
{
    if (i < 0)
        return 0;
    if (*(*(table + i) + w) != -1)
        return *(*(table + i) + w);

    if ((item + i)->weight > w)
    {
        *(*(table + i) + w) = knapsack_recur(w, item, i - 1, table);
        return *(*(table + i) + w);
    }
    else
    {
        *(*(table + i) + w) = max((item + i)->value + knapsack_recur(w - (item + i)->weight, item, i - 1, table),
                                  knapsack_recur(w, item, i - 1, table));
        return *(*(table + i) + w);
    }
}

int knapsack(int w, struct Item *item, int n)
{
    sort(n, item);

    int **table = malloc(n * sizeof(int *));
    for (int x = 0; x < n; x++)
    {
        *(table + x) = malloc((w + 1) * sizeof(int));
        for (int y = 0; y <= w; y++)
            *(*(table + x) + y) = -1;
    }

    return knapsack_recur(w, item, n - 1, table);
}

int main()
{
    int n, w;
    scanf("%d", &n);
    scanf("%d", &w);
    struct Item *item = malloc(n * sizeof(struct Item));

    for (int x = 0; x < n; x++)
        scanf("%d%d", &(item + x)->weight, &(item + x)->value);

    int soln = knapsack(w, item, n);
    printf("%d\n", soln);

    free(item);
}