#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    for (int x = 0; x < n; x++)
    {
        scanf("%d", (a + x));
    }
    for (int x = 0; x < n; x++)
    {
        printf("%d\n", *(a + x));
    }
    free(a);

    int n;
    scanf("%d", &n);
    char(*b)[10] = malloc(n * 10 * sizeof(char));

    for (int x = 0; x < n; x++)
    {
        scanf("%s", (b + x));
    }
    for (int x = 0; x < n; x++)
    {
        printf("%s\n", (b + x));
    }
    free(b);
}