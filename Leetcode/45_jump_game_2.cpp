#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }

        int n=nums.size();
        vector<int>dp(n,INT_MAX);
        for(int i=n-2;i>=0;i--){
            if(nums[i]!=0){
                for(int j=1;j<=nums[i] && i+j<n-1 ;j++){
                    if(dp[i+j]!=-1){
                        dp[i]=min(dp[i],dp[i+j]);
                    }
                }
                if(dp[i]==INT_MAX){
                    dp[i]=-1;
                }
                else{
                    dp[i]++;
                }
            }
            else{
                dp[i]=-1;
            }
        }

        return dp[0];
    }
};