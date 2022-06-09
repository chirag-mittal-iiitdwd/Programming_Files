#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,int>col;
    unordered_map<int,int>diag135;
    unordered_map<int,int>diag45;
    int count=0;

    bool isVaild(int rowIdx,int colIdx){
        if(col[colIdx]!=0 || diag135[colIdx+rowIdx]!=0 || diag45[rowIdx-colIdx]){
            return false;
        }
        return true;
    }

    void helper(int n,int rowIdx){
        if(rowIdx==n){
            count++;
            return;
        }
        else{
            for(int colIdx=0;colIdx<n;colIdx++){
                if(isVaild(rowIdx,colIdx)){
                    col[colIdx]=1;
                    diag135[colIdx+rowIdx]=1;
                    diag45[rowIdx-colIdx]=1;
                    helper(n,rowIdx+1);
                    col[colIdx]=0;
                    diag135[colIdx+rowIdx]=0;
                    diag45[rowIdx-colIdx]=0;
                }
            }
        }
    }
public:
    int totalNQueens(int n) {
        helper(n,0);
        return count;
    }
};