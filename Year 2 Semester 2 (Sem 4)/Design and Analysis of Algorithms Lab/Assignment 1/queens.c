#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void writeFile(int n, int **board)
{
    FILE *file;
    file = fopen("txt/queens.txt", "a");
    if (file == NULL)
        exit(1);
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            fprintf(file, "%d ", board[x][y]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
    fclose(file);
}

bool isSafe(int n, int **board, int i, int j)
{
    int j_left = j, j_right = j;
    while (i >= 0)
    {
        if ((j_left >= 0 && board[i][j_left] == 1) ||
            board[i][j] == 1 ||
            (j_right < n && board[i][j_right] == 1))
            return false;
        i -= 1;
        j_left -= 1;
        j_right += 1;
    }
    return true;
}

int queens_recur(int n, int **board, int i)
{
    if (i == n)
    {
        writeFile(n, board);
        return 1;
    }
    else
    {
        int solutions = 0;
        for (int j = 0; j < n; j++)
        {
            if (isSafe(n, board, i, j))
            {
                board[i][j] = 1;
                solutions += queens_recur(n, board, i + 1);
                board[i][j] = 0;
            }
        }
        return solutions;
    }
}

int queens(int n)
{
    int **board = malloc(n * sizeof(int *));
    for (int x = 0; x < n; x++)
        *(board + x) = calloc(n, sizeof(int));
    int solutions = queens_recur(n, board, 0);
    free(board);
    return solutions;
}

int main()
{
    int n;
    scanf("%d", &n);
    int solutions = queens(n);
    printf("%d\n", solutions);
}