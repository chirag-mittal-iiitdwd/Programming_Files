#include<bits/stdc++.h>
using namespace std;

#define noSign 1
#define neg 0
#define pos 2

class Solution {
    int recursion(int idx,vector<int>&nums,int sign,vector<vector<int>>&dp){
        if(idx==0){
            return 0;
        }
        if(dp[idx][sign]!=-1){
            return dp[idx][sign];
        }
        int notTake=recursion(idx-1,nums,sign,dp);
        int take=0;
        int curSign=nums[idx]-nums[idx-1]<0?neg:pos;
        int diff=nums[idx]-nums[idx-1];
        if(diff!=0){
            if(sign==noSign || curSign!=sign){
                take=recursion(idx-1,nums,curSign,dp)+1;   
            }
        }
        return dp[idx][sign] = max(notTake,take);
    }
    int tabulation(vector<int>&nums){
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(3,0));

        for(int i=1;i<n;i++){
            for(auto&sign:{noSign,neg,pos}){
                int notTake=dp[i-1][sign];
                int take=0;
                int curSign=nums[i]-nums[i-1]<0?neg:pos;
                int diff=nums[i]-nums[i-1];
                if(diff!=0){
                    if(sign==noSign || curSign!=sign){
                        take=dp[i-1][curSign]+1;   
                    }
                }
                dp[i][sign]=max(take,notTake);
            }
        }

        return max(dp[n-1][noSign],max(dp[n-1][pos],dp[n-1][neg]))+1;
    }
    
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
        if(n==2){
            return (nums[0]!=nums[1])+1;
        }
        return tabulation(nums);
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        int ans=recursion(n-1,nums,noSign,dp)+1;
        return ans;
    }
};