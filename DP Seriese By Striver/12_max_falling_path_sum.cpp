#include<bits/stdc++.h>
using namespace std;

int recursive(vector<vector<int>>&matrix,int curRow,int curCol,int n,int m){
    if(curRow==n-1){
        return matrix[curRow][curCol];
    }

    int ans=INT_MIN;
    int left=INT_MIN,right=INT_MIN;
    int down=recursive(matrix,curRow+1,curCol,n,m)+matrix[curRow][curCol];
    if(curCol-1>=0){
        left=recursive(matrix,curRow+1,curCol-1,n,m)+matrix[curRow][curCol];
    }
    if(curCol+1<m){
        right=recursive(matrix,curRow+1,curCol+1,n,m)+matrix[curRow][curCol];
    }
    ans=max(left,max(down,right));
    return ans;
}

int memoised(vector<vector<int>>&matrix,int curRow,int curCol,int n,int m,vector<vector<int>>&dp){
    if(curRow==n-1){
        return matrix[curRow][curCol];
    }
    if(dp[curRow][curCol]!=-1){
        return dp[curRow][curCol];
    }

    int left=INT_MIN,right=INT_MIN;
    int down=recursive(matrix,curRow+1,curCol,n,m)+matrix[curRow][curCol];
    if(curCol-1>=0){
        left=recursive(matrix,curRow+1,curCol-1,n,m)+matrix[curRow][curCol];
    }
    if(curCol+1<m){
        right=recursive(matrix,curRow+1,curCol+1,n,m)+matrix[curRow][curCol];
    }
    return dp[curRow][curCol]=max(left,max(down,right));
}

int tabulation(vector<vector<int>>&grid){
    int n=grid.size(),m=grid[0].size();
    if(n==1){
        return *max_element(grid[0].begin(),grid[0].end());
    }

    vector<vector<int>>dp(n,vector<int>(m,INT_MIN));
    dp[n-1]=grid[n-1];
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            int down=dp[i+1][j];
            int left=INT_MIN,right=INT_MIN;
            if(j-1>=0){
                left=dp[i+1][j-1];
            }
            if(j+1<m){
                right=dp[i+1][j+1];
            }
            dp[i][j]=max(right,max(down,left))+grid[i][j];
        }
    }

    return *max_element(dp[0].begin(),dp[0].end());
}

int spaceOptisation(vector<vector<int>>&grid){
    int n=grid.size(),m=grid[0].size();
    if(n==1){
        return *max_element(grid[0].begin(),grid[0].end());
    }

    vector<int>prev=grid[n-1];
    for(int i=n-2;i>=0;i--){
        vector<int>cur(m,INT_MIN);
        for(int j=0;j<m;j++){
            int down=prev[j];
            int left=INT_MIN,right=INT_MIN;
            if(j-1>=0){
                left=prev[j-1];
            }
            if(j+1<m){
                right=prev[j+1];
            }
            cur[j]=max(right,max(left,down))+grid[i][j];
        }
        prev=cur;
    }

    return *max_element(prev.begin(),prev.end());
}