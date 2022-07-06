#include<bits/stdc++.h>
using namespace std;

bool equalSumPartiton(vector<int>&nums){
    int n=nums.size();
    int sum=accumulate(nums.begin(),nums.end(),0);
    if(sum&1){
        return false;
    }
    int target=sum/2;
    vector<vector<bool>>dp(n,vector<bool>(target+1,false));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[0][nums[0]]=true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool notIncl=dp[i-1][j];
            bool incl=false;
            if(nums[i]<=j){
                incl=dp[i-1][j-nums[i]];
            }
            dp[i][j]=incl|notIncl;
        }
    }

    return dp[n-1][target];
}

bool equalSumPartitionSpaceOpt(vector<int>&nums,int n){
    int sum=accumulate(nums.begin(),nums.end(),0);
    if(sum&1){
        return false;
    }
    int target=sum/2;
    vector<bool>prev(target+1,false),cur(target+1,false);
    prev[0]=cur[0]=true;
    prev[nums[0]]=true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool notIncl=prev[j];
            bool incl=false;
            if(nums[i]<=j){
                incl=prev[j-nums[i]];
            }
            cur[j]=incl|notIncl;
        }
        prev=cur;
    }

    return prev[target];
}