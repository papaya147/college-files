// 21BDS0340 Abhinav Dinesh Srivatsa
/*
void printIndex_21BDS0340(int N, float *Bmi)
    Loop from 0 to N as X
        If Bmi[X] is between 18.6 and 24.9, then display X

Declare integer N
Read input and assign as N
Declare float array Bmi with N spaces
Loop from 0 to N as X
    Read input and assign as Bmi[X]
Call printIndex_21BDS0340() and pass N and Bmi as arguments
*/

#include <stdio.h>
#include <stdlib.h>

void printIndex_21BDS0340(int n, float *bmi)
{
    for (int x = 0; x < n; x++)
        if (*(bmi + x) >= 18.6 && *(bmi + x) <= 24.9)
            printf("%d\n", x);
}

int main()
{
    int n;
    scanf("%d", &n);
    float *bmi = malloc(n * sizeof(float));
    for (int x = 0; x < n; x++)
    {
        scanf("%f", (bmi + x));
    }
    printIndex_21BDS0340(n, bmi);
}