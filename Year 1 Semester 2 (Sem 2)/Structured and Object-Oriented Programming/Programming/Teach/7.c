#include <stdio.h>
#include <stdlib.h>

struct Test
{
    int data;
} T;

int main()
{
    T.data = 5;
    printf("%d", T.data);
}