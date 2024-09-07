// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
#include <string.h>
using namespace std;

class Parent
{
protected:
    char name[15];
    char phno[11];

public:
    virtual void read() = 0;

    virtual void display() = 0;
};

class Faculty : public Parent
{
    char empid[10];
    char course1[10];
    char course2[10];

public:
    void read()
    {
        cin.ignore();
        cin.getline(name, 15);
        cin >> phno >> empid >> course1 >> course2;
    }

    void display()
    {
        cout << course1 << "\n"
             << course2;
    }
};

class Staff : public Parent
{
    char staffid[10];
    char dep[15];

public:
    void read()
    {
        cin.ignore();
        cin.getline(name, 15);
        cin >> phno >> staffid >> dep;
    }

    void display()
    {
        cout << dep;
    }
};

int main()
{
    Parent *p;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        Faculty f;
        p = &f;
        break;
    }
    case 2:
    {
        Staff s;
        p = &s;
    }
    }
    p->read();
    p->display();
}