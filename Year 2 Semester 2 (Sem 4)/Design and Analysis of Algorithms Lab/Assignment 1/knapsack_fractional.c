#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int weight;
    int value;
    double unitary_value;
};

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
        int max = x;
        for (int y = x + 1; y < n; y++)
            if ((item + max)->unitary_value < (item + y)->unitary_value)
                max = y;
        swap(item + max, item + x);
    }
}

double knapsack(int w, int n, struct Item *item)
{
    for (int x = 0; x < n; x++)
        (item + x)->unitary_value = (item + x)->value / (item + x)->weight;

    sort(n, item);

    double value = 0;
    for (int x = 0; x < n; x++)
    {
        if (w - (item + x)->weight >= 0)
        {
            w -= (item + x)->weight;
            value += (item + x)->value;
        }
        else
        {
            value += w * (item + x)->unitary_value;
            w = 0;
        }
    }

    return value;
}

int main()
{
    int n, w;
    scanf("%d", &n);
    scanf("%d", &w);
    struct Item *item = malloc(n * sizeof(struct Item));

    for (int x = 0; x < n; x++)
        scanf("%d%d", &(item + x)->weight, &(item + x)->value);

    double soln = knapsack(w, n, item);
    printf("%.2f\n", soln);
    free(item);
}