#include <iostream>
#include <regex>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quick(int first, int last, int *arr)
{
    if (first >= last)
        return;
    int i = first, j = last;
    int p = rand() % (j - i + 1) + i;
    swap(arr + i, arr + p);
    p = i;
    while (i < j)
        if (p == i)
            if (arr[p] > arr[j])
            {
                swap(arr + p, arr + j);
                p = j;
            }
            else
                j--;
        else if (arr[p] < arr[i])
        {
            swap(arr + p, arr + i);
            p = i;
        }
        else
            i++;

    quick(first, j - 1, arr);
    quick(j + 1, last, arr);
}

int main()
{
    srand(time(0));
    int n;
    cin >> n;
    int *arr = new int[n];
    string input;
    getline(cin >> ws, input);
    regex exp("-*[0-9]+");
    smatch res;
    int i = 0;
    while (regex_search(input, res, exp, regex_constants::match_any) && i < n)
    {
        arr[i++] = stoi(res[0]);
        input = res.suffix().str();
    }
    quick(0, n - 1, arr);
    for (int x = 0; x < n; x++)
        cout << arr[x] << "\n";
    free(arr);
}