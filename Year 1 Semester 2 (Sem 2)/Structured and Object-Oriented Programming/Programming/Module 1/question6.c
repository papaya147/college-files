// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>

int main()
{
    int temps[] = {100, 357, 1187, 2193, 2660};
    int t;
    scanf("%d", &t);
    int flag = 0;
    for (int x = 0; x < sizeof(temps) / sizeof(temps[0]); x++)
    {
        int lowert = temps[x] * 0.95;
        int uppert = temps[x] * 1.05;
        if (t > lowert && t < uppert)
        {
            switch (x)
            {
            case 0:
                printf("Water");
                break;
            case 1:
                printf("Mercury");
                break;
            case 2:
                printf("Copper");
                break;
            case 3:
                printf("Silver");
                break;
            case 4:
                printf("Gold");
            }
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Substance unknown");
    }
}