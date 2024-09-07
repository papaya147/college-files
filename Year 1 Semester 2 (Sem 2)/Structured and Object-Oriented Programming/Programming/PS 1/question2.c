// 21BDS0340 Abhinav Dinesh Srivatsa
/*
Declare integers A, B, C
Declare character Op
Read all the above from input
Switch Op
    If Op is '+', then display A + B + C
    If Op is '-', then display absolute value of A - B - C
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    char op;
    scanf("%d%d%d %c", &a, &b, &c, &op);
    switch (op)
    {
    case '+':
        printf("%d", a + b + c);
        break;
    case '-':
        printf("%d", abs(a - b - c));
        break;
    }
}