// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
using namespace std;

class Student
{
    string name, regno;

public:
    friend ostream &operator<<(ostream &out, Student &s);
    friend istream &operator>>(istream &in, Student &s);
};

ostream &operator<<(ostream &out, Student &s)
{
    out << s.name << "\n"
        << s.regno;
    return out;
}
istream &operator>>(istream &in, Student &s)
{
    in >> s.name >> s.regno;
    return in;
}

template <class T>
void read(T t[], int n)
{
    for (int x = 0; x < n; x++)
        cin >> *(t + x);
}

template <class T>
void display(T t[], int n)
{
    for (int x = 0; x < n; x++)
        cout << *(t + x) << "\n";
}

int main()
{
    int n;
    cin >> n;
    int i[n];
    float f[n];
    string s[n];
    Student st[n];

    read(i, n);
    read(f, n);
    read(s, n);
    read(st, n);

    display(i, n);
    display(f, n);
    display(s, n);
    display(st, n);
}