#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<vector<char>> &board, int row, int col, char ch)
{

    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == ch)
        {
            return false;
        }
        if (board[row][i] == ch)
        {
            return false;
        }
    }

    int rowFactor = row - row % 3;
    int colFactor = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; i < 3; j++)
        {
            if (board[i + rowFactor][j + colFactor] == ch)
            {
                return false;
            }
        }
    }
    return true;
}

bool helper(vector<vector<char>> &board, int row, int col)
{
    if (row == 9)
    {
        return true;
    }

    if (col == 9)
    {
        return helper(board, row + 1, 0);
    }

    if (board[row][col] != '.')
    {
        return helper(board, row, col + 1);
    }

    for (char i = '1'; i <= '9'; i++)
    {
        if (isPossible(board, row, col, i))
        {
            board[row][col] = i;
            if (helper(board, row, col + 1))
            {
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}

public:
void solveSudoku(vector<vector<char>> &board)
{
    helper(board, 0, 0);
}
}
;