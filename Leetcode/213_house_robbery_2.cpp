#include<bits/stdc++.h>
using namespace std;

class Solution {
    int helper(vector<int>&nums,int n){
        vector<int>dp(n+1,0);
        dp[1]=nums[0];

        for(int i=1;i<n;i++){
            dp[i+1]=max(dp[i],dp[i-1]+nums[i]);
        }
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        vector<int>l(nums.begin() + 1, nums.end());
        vector<int>f(nums.begin(), nums.end()-1);
        return max(helper(f,n-1),helper(l,n-1));
    }
};