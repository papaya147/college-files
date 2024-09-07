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

class PartTimeEmployee : private Employee
{
    int NumberofHoursWorked;
    int HourlyWage;

public:
    void getPartTimeEmployee()
    {
        Employee::getEmp();
        cin >> NumberofHoursWorked >> HourlyWage;
    }

    void displayPartTimeEmployeeDetail()
    {
        Employee::dispEmp();
        cout << NumberofHoursWorked << "\n"
             << HourlyWage << "\n";
    }
};

int main()
{
    PartTimeEmployee p;
    p.getPartTimeEmployee();
    p.displayPartTimeEmployeeDetail();
}