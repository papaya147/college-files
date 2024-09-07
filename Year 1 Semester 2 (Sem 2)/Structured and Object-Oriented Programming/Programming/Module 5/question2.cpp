// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
using namespace std;

class Rectangle
{
    int length;
    int width;

public:
    void setLength(int length)
    {
        this->length = length;
    }

    void setWidth(int width)
    {
        this->width = width;
    }

    int getLength()
    {
        return this->length;
    }

    int getWidth()
    {
        return this->width;
    }

    int area(int length, int width)
    {
        return length * width;
    }
};

int main()
{
    Rectangle r[3];
    int length, width;
    for (int x = 0; x < 3; x++)
    {
        cin >> length >> width;
        (r + x)->setLength(length);
        (r + x)->setWidth(width);
    }
    for (int x = 0; x < 3; x++)
    {
        cout << (r + x)->area((r + x)->getLength(), (r + x)->getWidth()) << "\n";
    }
}