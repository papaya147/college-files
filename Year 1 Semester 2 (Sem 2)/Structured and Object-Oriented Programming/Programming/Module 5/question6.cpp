// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
using namespace std;

inline int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << factorial(n);
}