// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
using namespace std;

class Height
{
    int feet;
    int inch;

public:
    void setHeight(int feet, int inch)
    {
        this->feet = feet;
        this->inch = inch;
    }

    bool operator<(Height h)
    {
        if (this->feet < h.feet)
            return true;
        else if (this->feet == h.feet)
            if (this->inch < h.inch)
                return true;
        return false;
    }

    bool operator<=(Height h)
    {
        if (this->feet < h.feet)
            return true;
        else if (this->feet == h.feet)
            if (this->inch <= h.inch)
                return true;
        return false;
    }

    bool operator>(Height h)
    {
        if (this->feet > h.feet)
            return true;
        else if (this->feet == h.feet)
            if (this->inch > h.inch)
                return true;
        return false;
    }

    bool operator>=(Height h)
    {
        if (this->feet > h.feet)
            return true;
        else if (this->feet == h.feet)
            if (this->inch >= h.inch)
                return true;
        return false;
    }
};

int main()
{
    Height h1;
    Height h2;
    int i1, j1, i2, j2;
    cin >> i1 >> j1 >> i2 >> j2;
    h1.setHeight(i1, j1);
    h2.setHeight(i2, j2);
    if (h1 > h2)
        cout << "Taller";
    else if (h1 >= h2)
        cout << "Same";
    else if (h1 < h2)
        cout << "Shorter";
}