#include<bits/stdc++.h>
using namespace std;

int recursive(vector<int>&nums,int idx,int n){
    if(idx>=n){
        return 0;
    }
    int incl=recursive(nums,idx+2,n)+nums[idx];
    int notIncl=recursive(nums,idx+1,n);
    return max(incl,notIncl);
}

int memoRec(vector<int>&nums,vector<int>&dp,int idx,int n){
    if(idx>=n){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    return dp[idx]=max(memoRec(nums,dp,idx+2,n)+nums[idx],memoRec(nums,dp,idx+1,n));
}

int tabulation(vector<int>nums){
    int n=nums.size();
    if(n==1){
        return nums[0];
    }
    if(n==2){
        return max(nums[1],nums[0]);
    }
    vector<int>dp(n,0);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);

    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[n-1];
}

int spaceOptimisation(vector<int>&nums){
    int n=nums.size();
    if(n==1){
        return nums[0];
    }
    if(n==2){
        return max(nums[1],nums[0]);
    }

    int prev=max(nums[1],nums[0]),prev2=nums[0];

    for(int i=2;i<n;i++){
        int cur=max(prev,prev2+nums[i]);
        prev2=prev;
        prev=cur;
    }
    return prev;
}