#include<bits/stdc++.h>
using namespace std;

int recursive(vector<int>&nums,int n,int k,int idx){
    if(idx==0){
        return 0;
    }
    int mini=INT_MAX;
    for(int i=1;i<=k;i++){
        if(idx-i>=0){
            mini=min(mini,recursive(nums,n,k,idx-i)+abs(nums[i]-nums[idx-i]));
        }
        else{
            break;
        }
    }
    return mini;
}

int dynamicPro(vector<int>&nums,int n,int k,int idx,vector<int>&dp){
    if(idx==0){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    int mini=INT_MAX;
    for(int i=1;i<=k;i++){
        if(idx-i>=0){
            mini=min(mini,dynamicPro(nums,n,k,idx-i,dp)+abs(nums[i]-nums[idx-i]));
        }
    }
    return dp[idx]=mini;
}

int dynamicBottomUp(vector<int>&nums,int n,int k){
    vector<int>dp(n,0);

    for(int i=1;i<n;i++){
        int mini=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                mini=min(mini,dp[i-j]+abs(nums[i]-nums[i-j]));
            }
        }
        dp[i]=mini;
    }
    return dp[n-1];
}