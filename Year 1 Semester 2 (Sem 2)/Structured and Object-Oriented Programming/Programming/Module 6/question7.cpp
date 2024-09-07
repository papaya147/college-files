// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class Person
{
protected:
    char name[15];
    int age;
    char gender;

public:
    char *getName()
    {
        return this->name;
    }
};

class Sport
{
protected:
    char level[10];

public:
    char *getLevel()
    {
        return this->level;
    }
};

class Student : public Person, public Sport
{
    char regno[10];
    char school[10];
    float cgpa;

public:
    void getInput()
    {
        cin >> this->name >> this->age >> this->gender >> this->regno >> this->school >> this->cgpa >> this->level;
    }

    float getCGPA()
    {
        return this->cgpa;
    }

    void setCGPA(float cgpa)
    {
        this->cgpa = cgpa;
    }

    char *getRegno()
    {
        return this->regno;
    }
};

int main()
{
    Student s;
    s.getInput();
    if (strcmp(s.getLevel(), "State") == 0)
        s.setCGPA(s.getCGPA() + 0.5f);
    else if (strcmp(s.getLevel(), "National") == 0)
        s.setCGPA(s.getCGPA() + 1.0f);
    cout << fixed;
    cout << setprecision(1);
    cout << s.getName() << "\n"
         << s.getRegno() << "\n"
         << s.getCGPA();
}