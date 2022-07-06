#include<bits/stdc++.h>
using namespace std;

int recursive(vector<vector<int>>&grid,int i,int j1,int j2,int n,int m){
    if(j1<0 || j1>m-1 || j2<0 || j2>m-1){
        return -1e4;
    }
    if(i==n-1){
        return j1==j2?grid[i][j1]:grid[i][j1]+grid[i][j2];
    }

    int ans=INT_MIN;
    for(int dir1:{-1,0,1}){
        for(int dir2:{-1,0,1}){
            if(j1==j2){
                ans=max(ans,recursive(grid,i+1,j1+dir1,j2+dir2,n,m)+grid[i][j1]);
            }
            else{
                ans=max(ans,recursive(grid,i+1,j1+dir1,j2+dir2,n,m)+grid[i][j1]+grid[i][j2]);
            }
        }
    }
    return ans;
}

int dynamicPro(vector<vector<int>>&grid,int i,int j1,int j2,int n,int m,vector<vector<vector<int>>>&dp){
    if(j1<0 || j1>m-1 || j2<0 || j2>m-1){
        return -1e4;
    }
    if(i==n-1){
        return j1==j2?grid[i][j1]:grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }

    int ans=INT_MIN;
    for(int dir1:{-1,0,1}){
        for(int dir2:{-1,0,1}){
            if(j1==j2){
                ans=max(ans,dynamicPro(grid,i+1,j1+dir1,j2+dir2,n,m,dp)+grid[i][j1]);
            }
            else{
                ans=max(ans,dynamicPro(grid,i+1,j1+dir1,j2+dir2,n,m,dp)+grid[i][j1]+grid[i][j2]);
            }
        }
    }
    return dp[i][j1][j2]= ans;
}

// not correct need to check
int tabulation(vector<vector<int>>&grid,int n,int m){
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));

    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j2==j1){
                dp[n-1][j1][j2]=grid[n-1][j2];
            }
            else{
                dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int ans=INT_MIN;
                for(int dir1:{-1,0,1}){
                    for(int dir2:{-1,0,1}){
                        int val=0;
                        if(j1==j2){
                            val=grid[i][j1];
                        }
                        else{
                            val=grid[i][j1]+grid[i][j2];
                        }

                        if(j1+dir1>=0 && j1+dir1<m && j2+dir2>=0 && j2+dir2<m){
                            val+=dp[i+1][j1+dir1][j2+dir2];
                        }
                        else{
                            val+=(-1e8);
                        }

                        ans=max(ans,val);
                    }
                }
                return dp[i][j1][j2]= ans;
            }
        }
    }
}