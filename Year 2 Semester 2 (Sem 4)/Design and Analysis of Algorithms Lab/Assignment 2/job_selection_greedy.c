#include <stdio.h>
#include <stdlib.h>

struct Job
{
    int id;
    int deadline;
    int profit;
};

void swap(struct Job *x, struct Job *y)
{
    struct Job temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int n, struct Job *j)
{
    for (int x = 0; x < n - 1; x++)
        for (int y = x + 1; y < n; y++)
            if ((j + y)->profit > (j + x)->profit)
                swap(j + x, j + y);
}

int *job_select(int n, struct Job *j)
{
    int *result = malloc(n * sizeof(int));
    for (int x = 0; x < n; x++)
        *(result + x) = -1;
    for (int x = 0; x < n; x++)
        if (result[(j + x)->deadline] == -1)
            result[(j + x)->deadline] = (j + x)->id;
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Job *j = malloc(n * sizeof(struct Job));
    for (int x = 0; x < n; x++)
    {
        (j + x)->id = x;
        scanf("%d%d", &(j + x)->deadline, &(j + x)->profit);
    }
    sort(n, j);
    int *result = job_select(n, j);
    for (int x = 0; x < n; x++)
        printf("%d %d\n", (j + x)->deadline, (j + x)->profit);
    for (int x = 0; x < n; x++)
        printf("%c\n", *(result + x) + 97);
    free(j);
    free(result);
}