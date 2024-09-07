#include <stdio.h>
// ACSII
// a -> 97, z -> 122, A -> 65, Z -> 90

struct Student1
{
    char name[20];
    int age;
    char regno[10];
};

int main()
{
    struct Student1 r1;

    scanf("%d", &r1.age);
    printf("%d\n", r1.age);

    scanf("%s", r1.name);
    printf("%s\n", r1.name);
}