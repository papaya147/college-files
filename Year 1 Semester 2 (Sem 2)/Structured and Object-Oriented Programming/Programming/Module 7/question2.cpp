// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
using namespace std;

class Complex
{
    int real;
    int imag;

public:
    void display()
    {
        cout << real << "\n"
             << imag;
    }

    void setReal(int real)
    {
        this->real = real;
    }

    int getReal()
    {
        return real;
    }

    void setImag(int imag)
    {
        this->imag = imag;
    }

    int getImag()
    {
        return imag;
    }

    Complex operator-(Complex c)
    {
        Complex temp;
        temp.real = this->real - c.real;
        temp.imag = this->imag - c.imag;
        return temp;
    }

    Complex operator-()
    {
        Complex temp;
        temp.real = -this->real;
        temp.imag = -this->imag;
        return temp;
    }

    friend Complex operator+(Complex c1, Complex c2);
    friend Complex operator*(Complex c1, Complex c2);
};

Complex operator+(Complex c1, Complex c2)
{
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

Complex operator*(Complex c1, Complex c2)
{
    Complex temp;
    temp.real = c1.real * c2.real - c1.imag * c2.imag;
    temp.imag = c1.real * c2.imag + c1.imag * c2.real;
    return temp;
}

int main()
{
    int n, i;
    cin >> n;
    Complex c[n];
    for (int x = 0; x < n; x++)
    {
        cin >> i;
        c[x].setReal(i);
        cin >> i;
        c[x].setImag(i);
    }
    char op;
    cin >> op;
    Complex out = c[0];
    if (n == 1 && op == '-')
        out = -c[0];
    else
        for (int x = 1; x < n; x++)
        {
            switch (op)
            {
            case '+':
                out = out + c[x];
                break;

            case '-':
                out = out - c[x];
                break;

            case '*':
                out = out * c[x];
                break;
            }
        }
    out.display();
}