// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct date
{
    int d;
    int m;
    int y;
};

struct rain
{
    struct date date;
    int cm;
};

struct date dateToStruct(char array[11])
{
    struct date d;
    d.d = atoi(array);
    d.m = atoi(&array[3]);
    d.y = atoi(&array[6]);
    return d;
}

int main()
{
    int n;
    scanf("%d", &n);
    struct rain *r = malloc(n * sizeof(struct rain));
    char datestr[11];
    for (int x = 0; x < n; x++)
    {
        scanf("%s%d", datestr, &(r + x)->cm);
        (r + x)->date = dateToStruct(datestr);
    }
    int *month_rain = calloc(12, sizeof(int));
    int total_rain = 0;
    for (int x = 0; x < n; x++)
    {
        month_rain[(r + x)->date.m - 1] += (r + x)->cm;
        total_rain += (r + x)->cm;
    }
    for (int x = 0; x < 12; x++)
        if (month_rain[x] != 0)
            printf("%d\n%d\n", (x + 1), month_rain[x]);
    printf("%d", (int)round((float)total_rain / n));
    free(month_rain);
    free(r);
}