#include<bits/stdc++.h>
using namespace std;

class Solution {
    int memoised(vector<vector<int>>&matrix,int curRow,int curCol,int n,int m,vector<vector<int>>&dp){
        if(curRow==n-1){
            return matrix[curRow][curCol];
        }
        if(dp[curRow][curCol]!=-1){
            return dp[curRow][curCol];
        }

        int left=INT_MAX,right=INT_MAX;
        int down=memoised(matrix,curRow+1,curCol,n,m,dp)+matrix[curRow][curCol];
        if(curCol-1>=0){
            left=memoised(matrix,curRow+1,curCol-1,n,m,dp)+matrix[curRow][curCol];
        }
        if(curCol+1<m){
            right=memoised(matrix,curRow+1,curCol+1,n,m,dp)+matrix[curRow][curCol];
        }
        return dp[curRow][curCol]=min(left,min(down,right));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=INT_MAX;

        for(int i=0;i<m;i++){
            vector<vector<int>>dp(n,vector<int>(m,-1));
            ans=min(ans,memoised(grid,0,i,n,m,dp));
        }

        return ans;
    }
};