#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[10] = "papaya";
    char cop[10];
    strcpy(cop, str);
    printf("%s\n", cop);

    cop[4] = 'c';
    printf("%s %s\n", cop, str);

    printf("%d\n", strcmp(cop, str));

    if (strcmp(cop, str) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Diff\n");
    }

    char new[10] = "30-12-2001";
    int date = atoi(new);
    int month = atoi(&new[3]);
    int year = atoi(&new[6]);

    printf("%d, %d, %d\n", date, month, year);
}