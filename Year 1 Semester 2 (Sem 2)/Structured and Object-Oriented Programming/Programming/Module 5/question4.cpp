// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
#include <string.h>
using namespace std;

class Student
{
    char regno[10];
    char name[20];
    int age;

public:
    static char sec[10];
    static char uni[10];

    Student(char regno[10], char name[20], int age)
    {
        strcpy(this->regno, regno);
        strcpy(this->name, name);
        this->age = age;
    }

    void dispRegno()
    {
        cout << this->regno << "\n";
    }
};

char Student::sec[10];
char Student::uni[10];

int main()
{
    cin >> Student::sec;
    cin >> Student::uni;
    char regno[2][10];
    char name[2][20];
    int age[2];
    for (int x = 0; x < 2; x++)
        cin >> regno[x] >> name[x] >> age[x];
    Student s[2] = {Student(regno[0], name[0], age[0]), Student(regno[1], name[1], age[1])};
    for (int x = 0; x < 2; x++)
        s[x].dispRegno();
}