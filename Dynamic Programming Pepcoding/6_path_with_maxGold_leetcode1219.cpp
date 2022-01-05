#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dp[n][m];
        for(int j=m-1;j>=0;j--){
            for(int i=n-1;i>=0;i--){
                if(j==m-1){
                    dp[i][j]=grid[i][j];
                }
                else{
                    if(i==0){
                        dp[i][j]=max(dp[i+1][j+1],dp[i][j+1]);
                    }
                    else if(i==n-1){
                        dp[i][j]=max(dp[i][j+1],dp[i-1][j+1]);
                    }
                    else{
                        dp[i][j]=max(dp[i][j+1],max(dp[i+1][j+1],dp[i-1][j+1]));
                    }
                    dp[i][j]+=grid[i][j];
                }
            }
        }

        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,dp[i][0]);
        }
        return ans;
    }
};

