#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sortAscending(int n, int *array)
{
    int length = n;
    for (int x = 0; x < length - 1; x++)
        for (int y = x + 1; y < length; y++)
            if (array[x] > array[y])
                swap(array + x, array + y);
}

int main()
{
    // getting input
    int n, m;
    cout << "Enter number of blocks available: ";
    cin >> n;
    cout << "Enter number of processes: ";
    cin >> m;

    int *block = new int[n], *process = new int[m];
    for (int x = 0; x < n; x++)
    {
        cout << "Enter block size " << (x + 1) << ": ";
        cin >> block[x];
    }
    for (int x = 0; x < m; x++)
    {
        cout << "Enter process size " << (x + 1) << ": ";
        cin >> process[x];
    }

    bool assigned = false;
    for (int x = 0; x < m; x++)
    {
        sortAscending(n, block);
        assigned = false;
        for (int y = 0; y < n; y++)
        {
            if (process[x] <= block[y])
            {
                cout << "Process " << (x + 1) << ", size " << process[x]
                     << ": allocated to block of size " << block[y]
                     << "\n";
                block[y] -= process[x];
                assigned = true;
                break;
            }
        }
        if (!assigned)
            cout << "Process " << (x + 1) << ", size " << process[x] << ": Not allocated"
                 << "\n";
    }
}