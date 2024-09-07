// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>

void read_Board(int ttt[3][3])
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            scanf("%d", &ttt[x][y]);
        }
    }
}

int count_EmptyCell(int ttt[3][3])
{
    int count = 0;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (ttt[x][y] == -1)
            {
                count++;
            }
        }
    }
    return count;
}

int check_Rowwise(int ttt[3][3])
{
    int val;
    for (int x = 0; x < 3; x++)
    {
        val = ttt[x][0];
        if (ttt[x][1] == val && ttt[x][2] == val)
        {
            return val;
        }
    }
    return 0;
}

int check_Colwise(int ttt[3][3])
{
    int val;
    for (int x = 0; x < 3; x++)
    {
        val = ttt[0][x];
        if (ttt[1][x] == val && ttt[2][x] == val)
        {
            return val;
        }
    }
    return 0;
}

int check_Diagonalwise(int ttt[3][3])
{
    int val;
    // primary diagonal
    val = ttt[0][0];
    if (ttt[1][1] == val && ttt[2][2] == val)
    {
        return val;
    }
    // secondary diagonal
    val = ttt[0][2];
    if (ttt[1][1] == val && ttt[2][0] == val)
    {
        return val;
    }
    return 0;
}

int main()
{
    int ttt[3][3];
    read_Board(ttt);
    int emptycells = count_EmptyCell(ttt);
    if (emptycells == 9)
    {
        printf("Empty");
    }
    else if (emptycells == 0)
    {
        int rowwin = check_Rowwise(ttt);
        int colwin = check_Colwise(ttt);
        int diagwin = check_Diagonalwise(ttt);
        if (rowwin == 0 && colwin == 0 && diagwin == 0)
        {
            printf("Draw");
        }
        else if (rowwin != 0)
        {
            printf("Player%d wins", rowwin);
        }
        else if (colwin != 0)
        {
            printf("Player%d wins", colwin);
        }
        else if (diagwin != 0)
        {
            printf("Player%d wins", diagwin);
        }
    }
    else
    {
        printf("Intermediate");
    }
}