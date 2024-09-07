// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>

union data
{
    char aadhar[13];
    char pan[11];
    char voter[11];
};

int main()
{
    union data id;
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        scanf("%s", id.aadhar);
        printf("%s", id.aadhar);
        break;
    case 2:
        scanf("%s", id.pan);
        printf("%s", id.pan);
        break;
    case 3:
        scanf("%s", id.voter);
        printf("%s", id.voter);
        break;
    }
}