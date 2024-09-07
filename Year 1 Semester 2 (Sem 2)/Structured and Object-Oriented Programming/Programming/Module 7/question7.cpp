// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
#include <string.h>
using namespace std;

class Shape
{
protected:
    int height, width;

public:
    void setValues(int height, int width)
    {
        this->height = height;
        this->width = width;
    }

    virtual int area() = 0;
};

class Rectangle : public Shape
{
public:
    int area()
    {
        return height * width;
    }
};

class Triangle : public Shape
{
public:
    int area()
    {
        return height * width / 2;
    }
};

int main()
{
    int choice;
    cin >> choice;
    int height, width;
    cin >> height >> width;
    Shape *s;
    switch (choice)
    {
    case 1:
    {
        Rectangle r;
        s = &r;
        break;
    }
    case 2:
    {
        Triangle t;
        s = &t;
        break;
    }
    }
    s->setValues(height, width);
    cout << s->area();
}