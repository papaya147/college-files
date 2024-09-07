// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int x, y;
    cin >> x >> y;
    swap(&x, &y);
    cout << x << "\n"
         << y << "\n";
}