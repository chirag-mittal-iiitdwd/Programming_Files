#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isValid(int n, int m, int x, int y)
    {
        if (x >= 0 && x < n && y >= 0 && y < m)
        {
            return true;
        }
        return false;
    }
    int deadAndLive(vector<vector<int>> &board, int n, int m, int i, int j)
    {
        int live = 0, dead = 0;

        if (isValid(n, m, i - 1, j))
        {
            if (board[i - 1][j] == 1)
            {
                live++;
            }
        }
        if (isValid(n, m, i + 1, j))
        {
            if (board[i + 1][j] == 1)
            {
                live++;
            }
        }
        if (isValid(n, m, i, j - 1))
        {
            if (board[i][j - 1] == 1)
            {
                live++;
            }
        }
        if (isValid(n, m, i, j + 1))
        {
            if (board[i][j + 1] == 1)
            {
                live++;
            }
        }
        if (isValid(n, m, i - 1, j - 1))
        {
            if (board[i - 1][j - 1] == 1)
            {
                live++;
            }
        }
        if (isValid(n, m, i + 1, j + 1))
        {
            if (board[i + 1][j + 1] == 1)
            {
                live++;
            }
        }
        if (isValid(n, m, i - 1, j + 1))
        {
            if (board[i - 1][j + 1] == 1)
            {
                live++;
            }
        }
        if (isValid(n, m, i + 1, j - 1))
        {
            if (board[i + 1][j - 1] == 1)
            {
                live++;
            }
        }
        return live;
    }

public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> mat = board;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int live = deadAndLive(board, n, m, i, j);
                if (board[i][j] == 1 && (live < 2 || live > 3))
                {
                    mat[i][j] = 0;
                }
                else if (board[i][j] == 0 && live == 3)
                {
                    mat[i][j] = 1;
                }
            }
        }
        board = mat;
    }
};

class Solution
{
public:
    int get(vector<vector<int>> &board, int i, int j)
    {
        int sol = 0, n = board.size(), m = board[0].size();
        if (i > 0)
        {
            if (board[i - 1][j] == -1 or board[i - 1][j] >= 1)
                sol++;
            if (j > 0 and (board[i - 1][j - 1] == -1 or board[i - 1][j - 1] >= 1))
                sol++;
            if (j < m - 1 and (board[i - 1][j + 1] == -1 or board[i - 1][j + 1] >= 1))
                sol++;
        }
        if (i < n - 1)
        {
            if (board[i + 1][j] == -1 or board[i + 1][j] >= 1)
                sol++;
            if (j > 0 and (board[i + 1][j - 1] == -1 or board[i + 1][j - 1] >= 1))
                sol++;
            if (j < m - 1 and (board[i + 1][j + 1] == -1 or board[i + 1][j + 1] >= 1))
                sol++;
        }
        if (j > 0 and (board[i][j - 1] == -1 or board[i][j - 1] >= 1))
            sol++;
        if (j < m - 1 and (board[i][j + 1] == -1 or board[i][j + 1] >= 1))
            sol++;
        return sol;
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int k = get(board, i, j);
                if (board[i][j] == 0)
                {
                    if (k == 3)
                        board[i][j] = -2;
                }
                else
                {
                    if (k < 2 or k > 3)
                        board[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 0 or board[i][j] == 1)
                    continue;
                if (board[i][j] == -1)
                    board[i][j] = 0;
                else if (board[i][j] == -2)
                    board[i][j] = 1;
            }
        }
    }
};