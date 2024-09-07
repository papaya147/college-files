// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
using namespace std;

void dispChar(int n = 10, char c = '-')
{
    for (int x = 0; x < n; x++)
        cout << c;
}

int main()
{
    int choice;
    cin >> choice;
    if (choice == 1)
        dispChar();
    else
    {
        char c;
        int n;
        cin >> c >> n;
        dispChar(n, c);
    }
}