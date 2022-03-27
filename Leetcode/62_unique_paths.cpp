#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n,vector<int>(m));

        dp[n-1][m-1]=0;
        for(int i=0;i<n-1;i++){
            dp[i][m-1]=1;
        }

        for(int i=0;i<m-1;i++){
            dp[n-1][i]=1;
        }

        for(int j=m-2;j>=0;j--){
            for(int i=n-2;i>=0;i--){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};