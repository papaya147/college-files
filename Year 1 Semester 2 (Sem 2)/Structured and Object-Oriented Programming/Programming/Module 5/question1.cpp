// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
using namespace std;

class Test
{
    int testtime;
    int hour;
    int minute;

public:
    void readValues()
    {
        int tt, h, m;
        cin >> h >> m >> tt;
        testtime = tt;
        hour = h;
        minute = m;
    }

    void showEndTime()
    {
        minute += testtime;
        if (minute > 59)
        {
            hour += minute / 60;
            minute %= 60;
        }
        if (hour > 12)
            hour -= 12;

        if (hour < 10)
            cout << "0" << hour << ":";
        else
            cout << hour << ":";
        if (minute < 10)
            cout << "0" << minute;
        else
            cout << minute;
    }
};

int main()
{
    Test t;
    t.readValues();
    t.showEndTime();
}