#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        vector<bool>dp(n+1);
        dp[0]=false;
        dp[1]=true;
        if(n==1 || n==2 || n==3){
            return true;
        }
        dp[2]=dp[3]=true;

        for(int i=4;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(dp[i-j]==true){
                    dp[i-j]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};