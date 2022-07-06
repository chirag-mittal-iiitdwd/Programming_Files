#include<bits/stdc++.h>
using namespace std;

int recursive(vector<vector<int>>&matrix,int i,int j){
    if(i==0 && j==0){
        return matrix[i][j];
    }
    if(i<0 || j<0){
        return 0;
    }
    int up=INT_MAX,left=INT_MAX;
    if(i>0){
        up=recursive(matrix,i-1,j)+matrix[i][j];
    }
    if(j>0){
        left=recursive(matrix,i,j-1)+matrix[i][j];
    }
    return min(left,up);
}

int dynamicProgramming(vector<vector<int>>&dp,vector<vector<int>>&matrix,int i,int j){
    if(i==0 && j==0){
        return matrix[i][j];
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=INT_MAX,left=INT_MAX;
    if(i>0){
        up=dynamicProgramming(dp,matrix,i-1,j)+matrix[i][j];
    }
    if(j>0){
        left=dynamicProgramming(dp,matrix,i,j-1)+matrix[i][j];
    }
    return dp[i][j]=min(up,left);
}

int tabulation(vector<vector<int>>&matrix){
    int n=matrix.size(),m=matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,INT_MAX));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j]=matrix[i][j];
            }
            else{
                int up=INT_MAX,left=INT_MAX;
                if(i>0){
                    up=dp[i-1][j]+matrix[i][j];
                }
                if(j>0){
                    left=dp[i][j-1]+matrix[i][j];
                }
                dp[i][j]=min(up,left);
            }
        }
    }

    return dp[n-1][m-1];
}

int spaceOpt(vector<vector<int>>&matrix){
    int n=matrix.size(),m=matrix[0].size();
    vector<int>prev(m,INT_MAX);

    for(int i=0;i<n;i++){
        vector<int>curRow(m,INT_MAX);
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                curRow[j]=matrix[i][j];
            }
            else{
                int up=INT_MAX,left=INT_MAX;
                if(i>0){
                    up=prev[j]+matrix[i][j];
                }
                if(j>0){
                    left=curRow[j-1]+matrix[i][j];
                }
                curRow[j]=min(up,left);
            }
        }
        prev=curRow;
    }

    return prev[m-1];
}