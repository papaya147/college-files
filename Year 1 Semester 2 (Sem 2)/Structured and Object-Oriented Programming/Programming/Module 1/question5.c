// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>

int main()
{
    char c;
    scanf("%c", &c);
    int i = c;
    if (i >= 97)
    {
        i -= 32;
    }
    c = i;
    if (c == 'B')
    {
        printf("Battleship");
    }
    if (c == 'C')
    {
        printf("Cruiser");
    }
    if (c == 'D')
    {
        printf("Destroyer");
    }
    if (c == 'F')
    {
        printf("Frigate");
    }
}