// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct student
    {
        char regno[9];
        int cgpa;
        int no_courses;
        char (*courses)[8];
    };
    int n, m, mark;
    scanf("%d", &n);
    struct student *s = malloc(n * sizeof(*s));
    int totalcourses = 0;
    char(*totcour)[8] = malloc(totalcourses * sizeof(*totcour));
    for (int x = 0; x < n; x++)
    {
        scanf("%s", (s + x)->regno);
        scanf("%d", &m);
        (s + x)->no_courses = m;
        (s + x)->cgpa = 0;
        (s + x)->courses = malloc(m * sizeof(*(s + x)->courses));
        totcour = realloc(totcour, (totalcourses + m) * sizeof(*totcour));
        for (int y = 0; y < m; y++)
        {
            scanf("%s", *((s + x)->courses + y));
            strcpy(*(totcour + totalcourses + y), *((s + x)->courses + y));
            scanf("%d", &mark);
            (s + x)->cgpa += mark;
        }
        totalcourses += m;
    }
    for (int x = 0; x < n; x++)
        printf("%s\n%d\n", (s + x)->regno, (s + x)->cgpa);
    int *count = calloc(totalcourses, sizeof(int));
    for (int x = 0; x < totalcourses; x++)
        for (int y = x + 1; y < totalcourses; y++)
            if (strcmp(*(totcour + x), *(totcour + y)) == 0)
                (*(count + x))++;
    for (int x = 0; x < totalcourses; x++)
        if (*(count + x) == n - 1)
            printf("%s\n", *(totcour + x));
    for (int x = 0; x < n; x++)
        free((s + x)->courses);
    free(s);
    free(totcour);
    free(count);
}