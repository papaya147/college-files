// 21BDS0340 Abhinav Dinesh Srivatsa
/*
Declare structure staff with 5 fields:
    Character array Name with 15 spaces
    Integer Age
    Integer StaffID
    Integer Weight
    Integer Height

void readStaffInfo_21BDS0340(int N, struct staff *S)
    Loop from 0 to N as X
        Read 5 inputs and assign to S[X]'s Name, Age, StaffID, Weight and Height respectively

float bmi_21BDS0340(struct staff S)
    Declare float Bmi
    Calculate Bmi as S's Weight * 10000 / (S's Height)^2
    Return Bmi

Declare integer N
Read input and assign to N
Declare struct staff array S with N spaces
Call readStaffInfo_21BDS0340() and pass N and S as arguments
Loop from 0 to N as X
    Declare float Bmi and assign by calling bmi_21BDS0340() and pass S[X] as argument
    Display S[X]'s StaffID and Bmi
    If Bmi <= 18.5, then display "Underweight"
    Else if Bmi <= 24.9 and Bmi >= 18.6, then display "Ideal"
    Else if Bmi >= 25, then display "Overweight"
*/

#include <stdio.h>
#include <stdlib.h>

struct staff
{
    char name[15];
    int age;
    int staffID;
    int weight;
    int height;
};

void readStaffInfo_21BDS0340(int n, struct staff *s)
{
    for (int x = 0; x < n; x++)
        scanf("%s%d%d%d%d", (s + x)->name, &(s + x)->age, &(s + x)->staffID, &(s + x)->weight, &(s + x)->height);
}

float bmi_21BDS0340(struct staff s)
{
    float bmi = (float)s.weight * 10000 / (s.height * s.height);
    return bmi;
}

int main()
{
    int n;
    scanf("%d", &n);
    struct staff *s = malloc(n * sizeof(struct staff));
    readStaffInfo_21BDS0340(n, s);
    for (int x = 0; x < n; x++)
    {
        float bmi = bmi_21BDS0340(*(s + x));
        printf("%d\n%0.2f\n", (s + x)->staffID, bmi);
        if (bmi <= 18.5)
            printf("Underweight\n");
        else if (bmi >= 18.6 && bmi <= 24.9)
            printf("Ideal\n");
        else if (bmi >= 25.0)
            printf("Overweight\n");
    }
    free(s);
}