//21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    int p, d, i, t;
    for (int x = 0; x < n; x++)
    {
        scanf("%d %d %d %d", &p, &d, &i, &t);
        if (t == 36 || t == 48 || t == 60)
        {
            float loan = p - d;
            loan *= (float)i / 1200;
            float den = 1 - pow(1 + (float)i/1200, -(float)t);
            loan /= den;
            printf("%.2f\n", floor(loan * 100) / 100);
        }
    }
}