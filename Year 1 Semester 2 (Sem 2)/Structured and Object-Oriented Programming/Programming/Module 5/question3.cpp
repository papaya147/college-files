// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
public:
    int id;
    char name[10];
    char desig[12];
};

void getID(Employee e[5], char desig[10])
{
    for (int x = 0; x < 5; x++)
        if (strcmp((e + x)->desig, desig) == 0)
            cout << (e + x)->id << "\n";
}

void getDesig(Employee e[5], int id)
{
    for (int x = 0; x < 5; x++)
        if ((e + x)->id == id)
            cout << (e + x)->desig << "\n";
}

int main()
{
    Employee e[5];
    int id;
    char name[10];
    char desig[12];
    for (int x = 0; x < 5; x++)
    {
        cin >> id >> name >> desig;
        (e + x)->id = id;
        strcpy((e + x)->name, name);
        strcpy((e + x)->desig, desig);
    }
    cin >> desig;
    cin >> id;
    getID(e, desig);
    getDesig(e, id);
}