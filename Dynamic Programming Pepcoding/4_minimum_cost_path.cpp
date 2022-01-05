/*
    Given a matrix, we can only move down or right, find the least possible cost of reaching to the point mat[n][n]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int helper(int i,int j,int&n,int&m,vector<vector<int>>&grid){
        int val=grid[i][j];
        if(i==n-1 && j==m-1){
            return val;
        }
        else if(i==n-1){
            i++;
        }
        else if(j==m-1){
            j++;
        }
        else{
            helper(i,j,n,m,grid);
            helper(i,j,n,m,grid);
        }
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

    }
};