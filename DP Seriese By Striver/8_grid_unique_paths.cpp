#include<bits/stdc++.h>
using namespace std;

int recursive(int i,int j){
    if(i==0 && j==0){
        return 1;
    }
    if(j<0 || i<0){
        return 0;
    }
    return recursive(i-1,j)+recursive(i,j-1);
}

int memo(int i,int j,vector<vector<int>>&dp){
    if(i==0 && j==0){
        return 1;
    }
    if(j<0 || i<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]=memo(i-1,j,dp)+memo(i,j-1,dp);
}

int tabulation(int n,int m){
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            else{
                int first=0,second=0;
                if(i-1>=0){
                    first=dp[i-1][j];
                }
                if(j-1>=0){
                    second=dp[i][j-1];
                }
                dp[i][j]=first+second;
            }
        }
    }

    return dp[n-1][m-1];
}

int optimisation(int n,int m){
    vector<int>prev(m,0);
    for(int i=0;i<n;i++){
        vector<int>temp(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                temp[j]=1;
            }
            else{
                int up=0,left=0;
                if(i>0){
                    up=prev[j];
                }
                if(j>0){
                    left=temp[j-1];
                }
                temp[j]=left+up;
            }
        }
        prev=temp;
    }
    return prev[m-1];
}

int mostOptimal(int n,int m){
    int n=m+n-2;
    int r=m-1;
    double res=1;

    for(int i=1;i<=r;i++){
        res=res*(n-r+1)/i;
    }
    return (int)res;
}
