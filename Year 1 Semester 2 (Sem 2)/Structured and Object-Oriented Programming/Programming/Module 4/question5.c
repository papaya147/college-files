// 21BDS0340 ABhinav Dinesh Srivatsa

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int day;
    int month;
    int year;
} date;

typedef struct
{
    int id;
    char name[15];
    date join_date;
    char mob_no[11];
} emp;

date splitDate(char str[11])
{
    date d;
    d.day = atoi(&str[0]);
    d.month = atoi(&str[3]);
    d.year = atoi(&str[6]);
    return d;
}

int isSurprised(emp e)
{
    if (e.id % 5 == 0 && e.join_date.year < 2010)
        return 1;
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    emp *e = malloc(n * sizeof(emp));
    char date[11];
    for (int x = 0; x < n; x++)
    {
        scanf("%d%s%s%s", &(e + x)->id, (e + x)->name, date, (e + x)->mob_no);
        (e + x)->join_date = splitDate(date);
    }
    for (int x = 0; x < n; x++)
        if (isSurprised(*(e + x)) == 1)
            printf("%s\n%s\n", (e + x)->name, (e + x)->mob_no);
    free(e);
}