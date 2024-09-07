#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void readSudokuIntialState(int **board)
{
    FILE *file = fopen("txt/sudoku initial state.txt", "r");
    char ch = 'a';
    int i = 0, j = 0;
    while (ch != EOF)
    {
        ch = fgetc(file);
        if (ch > 57 || ch < 48)
            continue;
        if (j == 9)
        {
            i++;
            j = 0;
        }
        board[i][j++] = ch - 48;
    }

    fclose(file);
}

void displayBoard(int **board)
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
            printf("%d ", board[x][y]);
        printf("\n");
    }
}

// something wrong here
bool isValid(int **board, int value, int i, int j)
{
    int sub_row = i / 3 * 3, sub_col = j / 3 * 3;
    for (int x = 0; x < 9; x++)
        if (board[x][j] == value || board[i][x] == value)
            return false;
    for (int x = sub_row; x < sub_row + 3; x++)
        for (int y = sub_col; y < sub_col + 3; y++)
            if (board[x][x] == value)
                return false;
    return true;
}

void solve(int **board, int i, int j)
{
    displayBoard(board);
    printf("\n");
    sleep(1);
    if (i == 9)
    {
        displayBoard(board);
        exit(1);
        return;
    }
    if (j == 9)
        solve(board, i + 1, 0);
    if (board[i][j] != 0)
        solve(board, i, j + 1);
    for (int k = 1; k < 10; k++)
    {
        if (isValid(board, k, i, j))
        {
            board[i][j] = k;
            solve(board, i, j + 1);
            board[i][j] = 0;
        }
    }
}

int main()
{
    int **board = malloc(9 * sizeof(int *));
    for (int x = 0; x < 9; x++)
        *(board + x) = malloc(9 * sizeof(int));
    readSudokuIntialState(board);
    solve(board, 0, 0);
    free(board);
}