// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>

struct employee
{
    int empid;
    char name[10];
    int age;
    char dept[6];
    char desig[15];
    int salary;
};

void getValues_21BDS0340(struct employee *e)
{
    scanf("%d%s%d%s%s%d", &e->empid, e->name, &e->age, e->dept, e->desig, &e->salary);
}

void sort_21BDS0340(struct employee e[3])
{
    struct employee temp;
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2 - x; y++)
            if (e[y].age > e[y + 1].age)
            {
                temp = e[y];
                e[y] = e[y + 1];
                e[y + 1] = temp;
            }
}

int main()
{
    struct employee e[3];
    for (int x = 0; x < 3; x++)
    {
        getValues_21BDS0340(&e[x]);
    }
    sort_21BDS0340(e);
    for (int x = 2; x >= 0; x--)
    {
        printf("%d\n", e[x].empid);
    }
}