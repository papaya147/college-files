// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
using namespace std;

class Person
{
    char name[20];
    int age;
    char phno[11];

public:
    void getPerson()
    {
        cin >> this->name >> this->age >> this->phno;
    }

    void printPerson()
    {
        cout << this->name << "\n"
             << this->age << "\n"
             << this->phno << "\n";
    }
};

class Employee : private Person
{
    char desig[20];

public:
    int empId;

    void getEmp()
    {
        Person::getPerson();
        cin >> this->empId >> this->desig;
    }

    void dispEmp()
    {
        Person::printPerson();
        cout << this->empId << "\n"
             << this->desig << "\n";
    }
};

int main()
{
    int n;
    cin >> n;
    Employee e[n];
    for (int x = 0; x < n; x++)
        e[x].getEmp();
    for (int x = 0; x < n; x++)
        for (int y = x + 1; y < n; y++)
            if (e[x].empId > e[y].empId)
            {
                Employee temp = e[y];
                e[y] = e[x];
                e[x] = temp;
            }
    for (int x = 0; x < n; x++)
        cout << e[x].empId << "\n";
}