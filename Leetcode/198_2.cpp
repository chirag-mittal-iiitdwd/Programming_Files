#include<bits/stdc++.h>
using namespace std;

class Solution {
    int helper(vector<int>&dp,vector<int>&nums,int n,int i){
        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=max(helper(dp,nums,n,i+2)+nums[i],helper(dp,nums,n,i+1));
    }
public:
    int rob(vector<int>& nums) {
        int ans=0;
        vector<int>dp(nums.size(),-1);
        return helper(dp,nums,nums.size(),0);
    }
};


class Solution {
    int helper(vector<int>&dp,vector<int>&nums,int i){
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i] = max(helper(dp,nums,i-2)+nums[i],helper(dp,nums,i-1));
    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return helper(dp,nums,nums.size()-1);
    }
};