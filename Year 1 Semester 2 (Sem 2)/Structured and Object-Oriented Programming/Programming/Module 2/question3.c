// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    int mat1[r][c];
    int mat2[r][c];
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
        {
            scanf("%d", &mat1[x][y]);
        }
    }
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
        {
            scanf("%d", &mat2[x][y]);
        }
    }
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
        {
            printf("%d\n", mat1[x][y] + mat2[x][y]);
        }
    }
}