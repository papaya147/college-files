// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
#include <string.h>
using namespace std;

class Student
{
public:
    char regno[10];
    char name[20];
    float cgpa;
    char phno[11];
    char school[20];

    void getStudent()
    {
        cin >> regno >> name >> cgpa >> phno >> school;
    }

    void printStudent()
    {
        cout << regno << "\n"
             << name << "\n"
             << cgpa << "\n"
             << phno << "\n"
             << school << "\n";
    }
};

class Research
{
    char ResearchTitle[20];
    char GuideName[20];

public:
    void getResearch()
    {
        cin >> ResearchTitle >> GuideName;
    }

    void printResearch()
    {
        cout << ResearchTitle << "\n"
             << GuideName << "\n";
    }
};

class ResearchStudent : public Student, public Research
{
public:
    int NumberOfPapersPublished;
    int NumberOfConferencesAttended;

public:
    void getResearchStudent()
    {
        Student::getStudent();
        Research::getResearch();
        cin >> NumberOfPapersPublished >> NumberOfConferencesAttended;
    }

    void printResearchStudent()
    {
        Student::printStudent();
        Research::printResearch();
        cout << NumberOfPapersPublished << "\n"
             << NumberOfConferencesAttended << "\n";
    }
};

int main()
{
    int n;
    cin >> n;
    ResearchStudent rs[n];
    for (int x = 0; x < n; x++)
        rs[x].getResearchStudent();
    int max = rs[0].NumberOfPapersPublished;
    char regno[10];
    strcpy(regno, rs[0].regno);
    for (int x = 1; x < n; x++)
        if (rs[x].NumberOfPapersPublished > max)
        {
            max = rs[x].NumberOfPapersPublished;
            strcpy(regno, rs[x].regno);
        }
    cout << regno;
}