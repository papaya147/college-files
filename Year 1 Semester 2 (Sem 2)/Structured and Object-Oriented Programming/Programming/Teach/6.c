#include <stdio.h>
#include <string.h>

union var
{
    int a;
    char b[10];
    float c;
};

int main()
{
    union var v;
    v.a = 5;
    printf("%d\n", v.a);
    strcpy(v.b, "ronith");
    printf("%s\n", v.b);
    printf("%d\n", v.a);
    v.a = 6;
    printf("%s\n", v.b);
    printf("%d\n", v.a);
}