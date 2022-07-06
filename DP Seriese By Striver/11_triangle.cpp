#include<bits/stdc++.h>
using namespace std;

int recursive(int i,int j,int n,vector<vector<int>>&triangle){
    if(i==n-1){
        return triangle[n-1][j];
    }
    return min(recursive(i+1,j,n,triangle)+triangle[i][j],recursive(i+1,j+1,n,triangle)+triangle[i][j]);
}

int dynamicMemo(int i,int j,int n,vector<vector<int>>&triangle,vector<vector<int>>&dp){
    if(i==n-1){
        return triangle[n-1][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]=min(dynamicMemo(i+1,j,n,triangle,dp)+triangle[i][j],dynamicMemo(i+1,j+1,n,triangle,dp)+triangle[i][j]);
}

class Solution {
    int tabulation(vector<vector<int>>&triangle){
        int n=triangle.size();
        if(n==1){
            return triangle[0][0];
        }
        vector<vector<int>>dp(n,vector<int>(n,0));
        dp[n-1]=triangle[n-1];

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
            }
        }
        return dp[0][0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return tabulation(triangle);
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==1){
            return triangle[0][0];
        }

        vector<int>dp=triangle[n-1];
        for(int i=n-2;i>=0;i--){
            vector<int>temp(i);
            for(int j=0;j<=i;j++){
                temp[j]=min(dp[i],dp[i+1])+triangle[i][j];
            }
            dp=temp;
        }
        return dp[0];
    }
};