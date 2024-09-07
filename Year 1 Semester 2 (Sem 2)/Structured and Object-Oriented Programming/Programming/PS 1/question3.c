// 21BDS0340 Abhinav Dinesh Srivatsa
/*
readName_21BDS0340(char *Name)
    Read input and assign to Name
readMarks_21BDS0340(int Marks[3])
    Loop from 0 to 3 as X
        Read input and assign to Marks[X]
readClassAverage_21BDS0340(int *Avg)
    Read input and assign to Avg
AboveOrBelowAverage_21BDS0340(int *Marks)
    Declare integer Sum as 0
    Loop from 0 to 3 as X
        Calculate Sum as Sum + Marks[X]
    Return Sum / 3
Declare character array Name with 20 spaces
Declare integer array Marks with 3 spaces
Declare integer Avg
Declare integer Flag
Call readName_21BDS0340(Name)
Call readMarks_21BDS0340(Marks)
Check if all Marks are between 0 and 100
    If not, then display "Not in Range" and set Flag as 1
If Flag = 0, then
    Call readClassAverage_21BDS0340(Avg)
    Declare integer Mean by calling AboveOrBelowAverage_21BDS0340(Marks)
    If Mean > Avg, then display "StudentName has above Class Average score"
    If Mean = Avg, then display "StudentName has average score same as Class Average"
    If Mean < Avg, then display "StudentName has below Class Average score"
*/

#include <stdio.h>

void readName_21BDS0340(char *name)
{
    scanf("%s", name);
}

void readMarks_21BDS0340(int marks[3])
{
    for (int x = 0; x < 3; x++)
    {
        scanf("%d", &marks[x]);
    }
}

void readClassAverage_21BDS0340(int *avg)
{
    scanf("%d", avg);
}

int AboveOrBelowAverage_21BDS0340(int *marks)
{
    int sum = 0;
    for (int x = 0; x < 3; x++)
    {
        sum += marks[x];
    }
    return sum / 3;
}

int main()
{
    char name[20];
    int marks[3];
    int avg;
    int flag = 0;
    readName_21BDS0340(name);
    readMarks_21BDS0340(marks);
    for (int x = 0; x < 3; x++)
    {
        if (marks[x] < 0 || marks[x] > 100)
        {
            printf("Not in Range");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        readClassAverage_21BDS0340(&avg);
        int mean = AboveOrBelowAverage_21BDS0340(marks);
        if (mean > avg)
        {
            printf("%s has above Class Average score", name);
        }
        if (mean == avg)
        {
            printf("%s has average score same as Class Average", name);
        }
        if (mean < avg)
        {
            printf("%s has below Class Average score", name);
        }
    }
}