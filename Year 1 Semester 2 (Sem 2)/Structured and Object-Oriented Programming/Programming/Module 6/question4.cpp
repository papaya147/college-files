// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
#include <string.h>
using namespace std;

class Person
{
    char name[20];
    int age;

public:
    void getPerson()
    {
        cin >> name >> age;
    }

    void displayPerson()
    {
        cout << name << "\n"
             << age << "\n";
    }
};

class Student : public Person
{
    char regno[10];
    float cgpa;

public:
    void getStudent()
    {
        getPerson();
        cin >> regno >> cgpa;
    }

    void displayStudent()
    {
        displayPerson();
        cout << regno << "\n"
             << cgpa << "\n";
    }

    char *getRegno()
    {
        return this->regno;
    }
};

class GateScore
{
    char GateRegistrationNumber[20];
    int Score;
    char ExamCode[20];

public:
    void getGate()
    {
        cin >> GateRegistrationNumber >> Score >> ExamCode;
    }

    void displayGate()
    {
        cout << GateRegistrationNumber << "\n"
             << Score << "\n"
             << ExamCode << "\n";
    }

    char *getGateRegno()
    {
        return this->GateRegistrationNumber;
    }

    int getGateScore()
    {
        return this->Score;
    }
};

class PG_Student : public Student, public GateScore
{
    char deptName[10];

public:
    void getPGS()
    {
        getStudent();
        getGate();
        cin >> deptName;
    }

    void displayPgs()
    {
        displayStudent();
        displayGate();
        cout << deptName << "\n";
    }
};

int main()
{
    int n;
    cin >> n;
    PG_Student pgs[n];
    for (int x = 0; x < n; x++)
        pgs[x].getPGS();
    int max = pgs[0].getGateScore();
    char regno[10], gateRegno[20];
    strcpy(regno, pgs[0].getRegno());
    strcpy(gateRegno, pgs[0].getGateRegno());
    for (int x = 0; x < n; x++)
        if (pgs[x].getGateScore() > max)
        {
            max = pgs[x].getGateScore();
            strcpy(regno, pgs[x].getRegno());
            strcpy(gateRegno, pgs[x].getGateRegno());
        }
    cout << regno << "\n"
         << gateRegno << "\n";
}