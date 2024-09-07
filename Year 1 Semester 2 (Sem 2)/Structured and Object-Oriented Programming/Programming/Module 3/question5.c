// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, temp;
    scanf("%d", &n);
    char(*regno)[10] = malloc(n * sizeof(*regno));
    int *cred = calloc(n, sizeof(int));
    int total_courses = 0;
    char(*course)[8] = malloc(total_courses * sizeof(*course));
    for (int x = 0; x < n; x++)
    {
        scanf("%s", *(regno + x));
        *(regno + x)[9] = '\0';
        scanf("%d", &m);
        course = realloc(course, (m + total_courses) * sizeof(*course));
        for (int y = 0; y < m; y++)
        {
            scanf("%s", *(course + y + total_courses));
            *(course + y + total_courses)[7] = '\0';
            scanf("%d", &temp);
            *(cred + x) += temp;
        }
        total_courses += m;
    }
    for (int x = 0; x < n; x++)
        printf("%s\n%d\n", *(regno + x), *(cred + x));
    int *count = calloc(total_courses, sizeof(int));
    for (int x = 0; x < total_courses; x++)
        for (int y = x + 1; y < total_courses; y++)
            if (strcmp(*(course + x), *(course + y)) == 0)
                (*(count + x))++;
    for (int x = 0; x < total_courses; x++)
        if (*(count + x) == (n - 1))
            printf("%s\n", *(course + x));
    free(regno);
    free(cred);
    free(course);
    free(count);
}