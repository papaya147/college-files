// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
#include <string.h>
using namespace std;

class Person
{
    char name[15];
    int age;
    char gender;

public:
    Person(char name[15], int age, char gender)
    {
        strcpy(this->name, name);
        this->age = age;
        this->gender = gender;
    }

    char *getName()
    {
        return this->name;
    }
};

class Student : public Person
{
    char regno[10];
    char school[10];
    float cgpa;

public:
    Student(char name[15], int age, char gender, char regno[10], char school[10], float cgpa) : Person(name, age, gender)
    {
        strcpy(this->regno, regno);
        strcpy(this->school, school);
        this->cgpa = cgpa;
    }

    char *getRegno()
    {
        return this->regno;
    }
};

int main()
{
    char name[15];
    int age;
    char gender;
    char regno[10];
    char school[10];
    float cgpa;
    cin >> name >> age >> gender >> regno >> school >> cgpa;
    Student s(name, age, gender, regno, school, cgpa);
    cout << s.getName() << "\n"
         << s.getRegno();
}