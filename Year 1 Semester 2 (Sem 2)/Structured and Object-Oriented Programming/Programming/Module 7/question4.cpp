// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
#include <string.h>
using namespace std;

class Student
{
    char name[10];
    char regno[10];

public:
    void setData(char name[10], char regno[10])
    {
        strcpy(this->name, name);
        strcpy(this->regno, regno);
    }

    friend ostream &operator<<(ostream &out, Student &s);
};

ostream &operator<<(ostream &out, Student &s)
{
    out << s.name << " " << s.regno;
    return out;
}

class StudArr
{
public:
    Student s[4];

    Student &operator[](int i)
    {
        if (0 < i && i < 4)
            return s[i];
        cout << "Out of bound";
        char n[10] = "", r[10] = "";
        s[0].setData(n, r);
        return s[0];
    }
};

int main()
{
    StudArr st;
    char data1[10], data2[10];
    for (int x = 1; x < 4; x++)
    {
        cin >> data1 >> data2;
        st[x].setData(data1, data2);
    }
    int n;
    cin >> n;
    cout << st[n];
}