// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
#include <string.h>
using namespace std;

class Fare
{
    int passengers;
    char from[20];
    char to[20];
    int ticket_cost;
    char cader;

public:
    Fare(int p, char f[20], char t[20], int tc, char c)
    {
        this->passengers = p;
        strcpy(this->from, f);
        strcpy(this->to, t);
        this->ticket_cost = tc;
        this->cader = c;
    }

    friend class Price;
};

class Price
{
public:
    int calculate(Fare f)
    {
        switch (f.cader)
        {
        case 'A':
            return f.ticket_cost * f.passengers * 0.9;
        case 'B':
            return f.ticket_cost * f.passengers * 0.85;
        case 'C':
            return f.ticket_cost * f.passengers * 0.8;
        }
        return 0;
    }
};

int main()
{
    int p, tc;
    char fr[20], t[20], c;
    cin >> p >> fr >> t >> tc >> c;
    Fare f(p, fr, t, tc, c);
    Price pr;
    cout << pr.calculate(f);
}