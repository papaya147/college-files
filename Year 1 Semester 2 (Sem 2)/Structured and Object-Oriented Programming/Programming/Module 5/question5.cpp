// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
#include <string.h>
using namespace std;

class Student
{
    char regno[10];
    char name[15];
    int age;

public:
    void setValues(char regno[10], char name[15], int age)
    {
        strcpy(this->regno, regno);
        strcpy(this->name, name);
        this->age = age;
    }

    char *getRegno()
    {
        return this->regno;
    }

    char *getName()
    {
        return this->name;
    }

    int getAge()
    {
        return this->age;
    }

    void displayInfo()
    {
        cout << this->getRegno() << "\n"
             << this->getName() << "\n"
             << this->getAge() << "\n";
    }
};

void printInfo(Student s)
{
    cout << s.getRegno() << "\n"
         << s.getName() << "\n"
         << s.getAge() << "\n";
}

int main()
{
    Student s1, s2;
    char regno[10], name[15];
    int age;
    cin >> regno >> name >> age;
    s1.setValues(regno, name, age);
    cin >> regno >> name >> age;
    s2.setValues(regno, name, age);

    s1.displayInfo();
    printInfo(s2);
}