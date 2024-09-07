#include <iostream>
#include <math.h>
using namespace std;

int karatsuba(int x, int y)
{
    if (x / 10 == 0 && y / 10 == 0)
        return x * y;
    int n = max(to_string(x).length() / 2, to_string(y).length() / 2);
    int part = pow(10, n);
    int xh = x / part, xl = x % part;
    int yh = y / part, yl = y % part;
    int h = karatsuba(xh, yh);
    int l = karatsuba(xl, yl);
    int m = karatsuba(xh + xl, yh + yl) - h - l;
    return h * pow(10, n * 2) + m * pow(10, n) + l;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << karatsuba(x, y);
}