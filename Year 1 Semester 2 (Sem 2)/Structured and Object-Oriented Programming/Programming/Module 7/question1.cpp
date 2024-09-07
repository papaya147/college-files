// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
using namespace std;

class Regular
{
    int basic;
    int hra;
    int da;

public:
    Regular(int basic, int hra, int da)
    {
        this->basic = basic;
        this->hra = hra;
        this->da = da;
    }

    int getPay()
    {
        return basic + hra + da * basic / 100;
    }
};

class Daily
{
    int wpa;
    int hours;

public:
    Daily(int wpa, int hours)
    {
        this->wpa = wpa;
        this->hours = hours;
    }

    int getPay()
    {
        return wpa * hours;
    }
};

class Consolidated
{
    int amount;

public:
    Consolidated(int amount)
    {
        this->amount = amount;
    }

    int getPay()
    {
        return amount;
    }
};

int main()
{
    int choice, i1, i2, i3;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cin >> i1 >> i2 >> i3;
        Regular r(i1, i2, i3);
        cout << r.getPay();
        break;
    }
    case 2:
    {
        cin >> i1 >> i2;
        Daily d(i1, i2);
        cout << d.getPay();
        break;
    }
    case 3:
    {
        cin >> i1;
        Consolidated c(i1);
        cout << c.getPay();
    }
    }
}