/*
    1.  Start from (0,0) you want to reach (8,8)
    2.  Try out all valid combinations
    3.  ans=false, currently at (x,y)
    4.  if
            ans = already filled, move to next block
        else
            for ( numbers = 1 to 9)
                if you can place number at (x,y)
                    ans=ans or place number at (x,y) and move to next block
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    vector<vector<char>> soduku = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
}