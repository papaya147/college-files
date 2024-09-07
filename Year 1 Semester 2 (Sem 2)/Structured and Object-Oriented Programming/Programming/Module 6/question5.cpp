// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
    char empid[10];
    char name[20];
    char phno[11];

public:
    void readEmployee()
    {
        cin >> empid;
        cin.ignore();
        cin.getline(name, 20);
        cin >> phno;
    }

    void displayEmployee()
    {
        cout << empid << "\n"
             << name << "\n"
             << phno << "\n";
    }

    char *getEmpid()
    {
        return this->empid;
    }
};

class PermanentEmployee : public Employee
{
    char department[15];
    int basicSalary;
    int HRA;
    int DA;

public:
    void readPermanentEmployee()
    {
        readEmployee();
        cin.ignore();
        cin.getline(department, 15);
        cin >> basicSalary >> HRA >> DA;
    }

    void displayPermanentEmployee()
    {
        displayEmployee();
        cout << department << "\n"
             << basicSalary << "\n"
             << HRA << "\n"
             << DA << "\n";
    }

    int calcSalary()
    {
        return basicSalary + (HRA + DA) * basicSalary / 100;
    }
};

class TemporaryEmployee : public Employee
{
    char contractorName[20];
    int salary;

public:
    void readTemporaryEmployee()
    {
        readEmployee();
        cin.ignore();
        cin.getline(contractorName, 20);
        cin >> salary;
    }

    void displayTemporaryEmployee()
    {
        displayEmployee();
        cout << contractorName << "\n"
             << salary << "\n";
    }

    int getSalary()
    {
        return this->salary;
    }
};

int main()
{
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        PermanentEmployee pe;
        pe.readPermanentEmployee();
        cout << pe.getEmpid() << "\n"
             << pe.calcSalary() << "\n";
        break;
    case 2:
        TemporaryEmployee te;
        te.readTemporaryEmployee();
        cout << te.getEmpid() << "\n"
             << te.getSalary() << "\n";
    }
}