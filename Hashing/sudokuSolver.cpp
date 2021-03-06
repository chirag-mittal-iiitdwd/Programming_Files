/*
https://www.youtube.com/watch?v=FWAIf_EVUKE
    1.  Find out the empty place
    2.  Try all possible values and if any any value is possible than 
        Recursively call the function
    3.  But if you find out at any future place than some previous step was wrong
        and we are not able to from answer than backtrack.
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char c){
    for (int i = 0; i < 9; i++){
        if (board[i][col] == c)
            return false;

        if (board[row][i] == c)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solve(vector<vector<char>> &board){
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            if (board[i][j] == '.'){
                for (char c = '1'; c <= '9'; c++){
                    if (isValid(board, i, j, c)){
                        board[i][j] = c;

                        if (solve(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board){
    solve(board);
}

int main(){
    vector<vector<char>> soduku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    solveSudoku(soduku);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout << soduku[i][j] << " ";
        }
        cout << endl;
    }
}