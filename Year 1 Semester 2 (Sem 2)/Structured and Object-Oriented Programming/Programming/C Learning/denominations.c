#include <stdio.h>

int main()
{
    int den[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int value;
    scanf("%d", &value);

    for (int x = 0; x < sizeof(den) / sizeof(den[0]); x++)
    {
        int num = value / den[x];
        value %= den[x];
        printf("%d X %d\n", den[x], num);
    }
}