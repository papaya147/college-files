#include <stdio.h>
#include <math.h>

int karatsuba(int p, int q)
{
    if (p / 10 == 0 && q / 10 == 0)
    {
        return p * q;
    }
    // always want p as larger number
    if (q > p)
    {
        int temp = p;
        p = q;
        q = temp;
    }
    int copy_p = p;
    int size = 0;
    while (copy_p != 0)
    {
        copy_p /= 10;
        size++;
    }
    int n = size / 2;
    int split = pow(10, n);
    int a = p / split;
    int b = p % split;
    int c = q / split;
    int d = q % split;
    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int ad_plus_bc = karatsuba(a + b, c + d) - ac - bd;
    return ac * (int)pow(10, 2 * n) + ad_plus_bc * (int)pow(10, n) + bd;
}

int main()
{
    int p = 120098;
    int q = 76398;
    int prod = karatsuba(p, q);
    printf("%d\n", prod);
    printf("%d\n", (p * q));
}