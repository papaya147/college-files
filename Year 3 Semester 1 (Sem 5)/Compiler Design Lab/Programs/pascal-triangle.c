#include <stdio.h>

int factorial(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return n * factorial(n - 1);
}

int combination(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main()
{
    int n, value;
    scanf("%d", &n);
    for (int x = 0; x <= n; x++)
    {
        for (int y = 0; y < x + 1; y++)
            printf("%d ", combination(x, y));
        printf("\n");
    }
}