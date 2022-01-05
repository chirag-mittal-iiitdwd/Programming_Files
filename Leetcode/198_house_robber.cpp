#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        else if(n==2){
            return max(nums[0],nums[1]);
        }
        else{
            vector<int>dp(n);
            dp[n-1]=nums[n-1];
            dp[n-2]=nums[n-2];
            for(int i=n-3;i>=0;i--){
                int maxi=INT_MIN;
                for(int j=i+2;j<n;j++){
                    maxi=max(maxi,dp[j]);
                }
                dp[i]=nums[i]+maxi;
            }
            return max(dp[0],dp[1]);
        }
    }
};

class Solution{
    public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        else if(n==2){
            return max(nums[0],nums[1]);
        }
        else{
            vector<int>dp(n);
            dp[0]=nums[0];
            dp[1]=max(nums[0],nums[1]);
            for(int i=2;i<n;i++){
                dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
            }
            return dp[n-1];
        }
    }
};