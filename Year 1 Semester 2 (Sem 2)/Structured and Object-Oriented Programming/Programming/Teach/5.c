#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *a = calloc(n, sizeof(int));
    for (int x = 0; x < n; x++)
    {
        scanf("%d", (a + x));
    }
    for (int x = 0; x < n; x++)
    {
        printf("%d\n", *(a + x));
    }
    free(a);
}