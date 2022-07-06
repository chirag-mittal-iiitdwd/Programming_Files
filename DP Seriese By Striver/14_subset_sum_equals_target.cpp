#include<bits/stdc++.h>
using namespace std;

bool recursive(vector<int>&nums,int target,int iter){
    if(target==0){
        return true;
    }
    if(iter==0){
        return nums[0]==target;
    }

    bool ans=false;
    ans=recursive(nums,target,iter-1);
    if(ans){
        return ans;
    }
    if(nums[iter]<=target){
        ans=recursive(nums,target-nums[iter],iter-1);
    }
    return ans;
}

bool dynamicPro(vector<int>&nums,int target,int iter,vector<vector<int>>&dp){
    if(target==0){
        return true;
    }
    if(iter==0){
        return nums[0]==target;
    }
    if(dp[iter][target]!=-1){
        return dp[iter][target];
    }

    bool ans=false;
    ans=dynamicPro(nums,target,iter-1,dp);
    if(ans){
        return ans;
    }
    if(nums[iter]<=target){
        ans=dynamicPro(nums,target-nums[iter],iter-1,dp);
    }
    return dp[iter][target] = ans;
}

bool tabulation(vector<int>&nums,int target,int n){
    vector<vector<bool>>dp(n,vector<bool>(target+1,false));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[0][nums[0]]=true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool notTake=dp[i-1][j];
            bool take=false;
            if(nums[i]<=j){
                take=dp[i-1][j-nums[i]];
            }
            dp[i][j]=take|notTake;
        }
    }
    return dp[n-1][target];
}

bool spaceOpt(vector<int>&nums,int target,int n){
    vector<bool>prev(target+1,false),cur(target+1,false);
    prev[0]=cur[0]=true;
    prev[nums[0]]=true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool notTake=prev[j];
            bool take=false;
            if(nums[i]<=j){
                take=prev[j-nums[i]];
            }
            cur[j]=take|notTake;
        }
        prev=cur;
    }
    return prev[target];
}