// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>
#include <string.h>

struct student
{
    char regis[9];
    float cgpa;
} s2;

int main()
{
    struct student s1, s[2];
    scanf("%s%f", s1.regis, &s1.cgpa);
    scanf("%s%f", s2.regis, &s2.cgpa);
    for (int x = 0; x < 2; x++)
    {
        scanf("%s%f", s[x].regis, &s[x].cgpa);
    }
    printf("%s\n%.1f\n", s1.regis, s1.cgpa);
    printf("%s\n%.1f\n", s2.regis, s2.cgpa);
    for (int x = 0; x < 2; x++)
    {
        printf("%s\n%.1f\n", s[x].regis, s[x].cgpa);
    }
}