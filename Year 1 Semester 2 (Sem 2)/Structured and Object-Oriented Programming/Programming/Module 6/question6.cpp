// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
#include <string.h>
using namespace std;

class Customer
{
    char name[20];
    char acc_num[25];
    char acc_type[10];
    char status[8];
    int balance;
    char last_date[11];

public:
    void getInput()
    {
        cin >> this->name >> this->acc_num >> this->acc_type >> this->status >> this->balance >> this->last_date;
    }

    char *getAccNum()
    {
        return this->acc_num;
    }

    char *getName()
    {
        return this->name;
    }

    int getBalance()
    {
        return this->balance;
    }

    char *getStatus()
    {
        return this->status;
    }

    void withdraw(int amt)
    {
        if (this->balance - amt < 1000)
            return; // transaction denied
        this->balance -= amt;
    }

    void deposit(int amt)
    {
        this->balance += amt;
    }

    void checkStatus()
    {
        char *date = (char *)"19-05-2022";
        int day = atoi(date);
        int month = atoi(&date[3]);
        int year = atoi(&date[6]);
        int last_day = atoi(this->last_date);
        int last_month = atoi(&this->last_date[3]);
        int last_year = atoi(&this->last_date[6]);
        if (year > last_year)
        {
            if (month > last_month)
                strcpy(this->status, "dormant");
            if (month == last_month && day > last_day)
                strcpy(this->status, "dormant");
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Customer c[n];
    for (int x = 0; x < n; x++)
        c[x].getInput();
    char acc_num[25];
    int choice, amt, index;
    cin >> acc_num >> choice;
    for (int x = 0; x < n; x++)
        if (strcmp(c[x].getAccNum(), acc_num) == 0)
            index = x;
    switch (choice)
    {
    case 1:
        cout << c[index].getName();
        break;
    case 2:
        cin >> amt;
        c[index].withdraw(amt);
        break;
    case 3:
        cin >> amt;
        c[index].deposit(amt);
    }
    for (int x = 0; x < n; x++)
    {
        c[x].checkStatus();
        cout << c[x].getAccNum() << "\n"
             << c[x].getBalance() << "\n"
             << c[x].getStatus() << "\n";
    }
}