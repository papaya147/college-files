// input:
//     {{0,0},{0,3},{3,0},{3,3},{1,1},{1,2},{2,1},{2,2}}
// output:
//     (3, 0)
//     (3, 3)
//     (0, 3)
//     (0, 0)

// input:
//     {(-7,8), (-4,6), (2,6), (6,4), (8,6), (7,-2), (4,-6), (8,-7),(0,0),
//     (3,-2),(6,-10),(0,-6),(-9,-5),(-8,-2),(-8,0),(-10,3),(-2,2),(-10,4)}
// output:
//     (6, -10)
//     (8, -7)
//     (8, 6)
//     (-7, 8)
//     (-10, 4)
//     (-10, 3)
//     (-9, -5)

#include <iostream>
#include <math.h>
#include <cmath>
#include <regex>
using namespace std;

template <typename T>
class Stack
{
public:
    T *arr;
    int length;
    int top;

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

class Vertex
{
public:
    int x;
    int y;
    double angle;

    Vertex()
    {
        this->x = 0;
        this->y = 0;
    }

    Vertex(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void set(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    double length()
    {
        return pow(pow(this->x, 2) + pow(this->y, 2), 0.5);
    }
};

double getAngle(Vertex v1, Vertex v2)
{
    Vertex *AB = new Vertex(1, 0);
    Vertex *BC = new Vertex(v2.x - v1.x, v2.y - v1.y);
    double dot = AB->x * BC->x + AB->y * BC->y;
    dot /= AB->length() * BC->length();
    double angle = acos(dot);
    free(AB);
    free(BC);
    return angle;
}

double getAngle(Vertex v1, Vertex v2, Vertex v3)
{
    Vertex *AB = new Vertex(v2.x - v1.x, v2.y - v1.y);
    Vertex *BC = new Vertex(v3.x - v2.x, v3.y - v2.y);
    double det = AB->x * BC->y - AB->y * BC->x;
    det /= AB->length() * BC->length();
    double angle = asin(det);
    free(AB);
    free(BC);
    return angle;
}

void sort(Vertex *vert, int n)
{
    for (int x = 1; x < n - 1; x++)
        for (int y = x + 1; y < n; y++)
            if (vert[x].angle > vert[y].angle)
            {
                Vertex temp = vert[x];
                vert[x] = vert[y];
                vert[y] = temp;
            }
            else if (vert[x].angle == vert[y].angle && vert[x].length() < vert[y].length())
            {
                Vertex temp = vert[x];
                vert[x] = vert[y];
                vert[y] = temp;
            }
}

void grahamsScan(int n, Vertex vert[], Stack<Vertex> *s)
{
    s->push(vert[0]);
    s->push(vert[1]);
    int x = 2;
    Vertex v1, v2, v3;
    while (x < n)
    {
        v3 = vert[x];
        v2 = s->pop();
        v1 = s->pop();
        if (getAngle(v1, v2, v3) > 0)
        {
            s->push(v1);
            s->push(v2);
            s->push(v3);
            x++;
        }
        else
        {
            s->push(v1);
        }
    }
}

int main()
{
    string input;
    getline(cin, input);
    regex exp("-*[0-9]+");
    smatch res;
    Stack<int> *digits = new Stack<int>(input.length());
    int digit;

    // getting digits
    while (regex_search(input, res, exp, regex_constants::match_any))
    {
        digit = stoi(res[0]);
        digits->push(digit);
        input = res.suffix().str();
    }

    // creating vertices
    int n = (digits->top + 1) / 2;
    Vertex *vert = new Vertex[n];
    int i = 0;
    while (!digits->isEmpty())
    {
        int y = digits->pop();
        int x = digits->pop();
        vert[i++].set(x, y);
    }

    Stack<Vertex> *s = new Stack<Vertex>(n);

    int l = 0;

    // getting lowest vertex
    for (int x = 0; x < n; x++)
        if (vert[l].y > vert[x].y)
            l = x;

    // swap lowest and 0
    Vertex temp = vert[0];
    vert[0] = vert[l];
    vert[l] = temp;

    // calculate angles for every vertex and sort
    for (int x = 1; x < n; x++)
        vert[x].angle = getAngle(vert[0], vert[x]);
    sort(vert, n);

    grahamsScan(n, vert, s);

    for (int x = 0; x <= s->top; x++)
        cout << "(" << s->arr[x].x << ", " << s->arr[x].y << ")\n";

    free(vert);
    free(s);
    free(digits);
}