#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();

        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1){
            return 0;
        }

        vector<vector<int>>dp(n,vector<int>(m));

        bool flag=true;
        for(int i=0;i<n;i++){
            dp[i][0]=((obstacleGrid[i][0]==1 || !flag)?flag=false:flag);
        }
        flag=true;
        for(int i=0;i<m;i++){
            dp[0][i]=((obstacleGrid[0][i]==1 || !flag)?flag=false:flag);
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=(obstacleGrid[i][j]==1?0:dp[i-1][j]+dp[i][j-1]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return dp[n-1][m-1];
    }
};
