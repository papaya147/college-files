#include <iostream>
#include <regex>
#include <math.h>
using namespace std;

template <typename T>
class Stack
{
public:
    T *arr;
    int top;
    int length;

    Stack<T>(int n)
    {
        this->length = n;
        this->arr = new T[n];
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == length - 1;
    }

    void push(T n)
    {
        if (!isFull())
            this->arr[++top] = n;
    }

    T pop()
    {
        if (!isEmpty())
            return this->arr[top--];
        return this->arr[0];
    }
};

int main()
{
    string input;
    getline(cin, input);
    regex exp("-*[0-9]+");
    smatch res;
    int digit;
    Stack<int> *digits = new Stack<int>(input.length());
    while (regex_search(input, res, exp, regex_constants::match_any))
    {
        digits->push(stoi(res[0]));
        input = res.suffix().str();
    }

    int n = pow(digits->top + 1, 0.5);
    int **matrix = new int *[n];
    for (int x = 0; x < n; x++)
        matrix[x] = new int[n];
    for (int x = n - 1; x >= 0; x--)
        for (int y = n - 1; y >= 0; y--)
        {
            digit = digits->pop();
            if (digit != -1)
                matrix[x][y] = digit;
            else
                matrix[x][y] = 10000;
        }

    for (int x = 0; x < n; x++)
        for (int i = 0; i < n; i++)
            if (i != x)
                for (int j = 0; j < n; j++)
                    if (j != x)
                        matrix[i][j] = matrix[i][j] < matrix[i][x] + matrix[x][j] ? matrix[i][j] : matrix[i][x] + matrix[x][j];

    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            if (matrix[x][y] == 10000)
                matrix[x][y] = -1;

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
            cout << matrix[x][y] << " ";
        cout << "\n";
    }

    free(digits);
    free(matrix);
}