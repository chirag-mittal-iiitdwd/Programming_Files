#include<bits/stdc++.h>
using namespace std;

int mod = (int)(1e9+7);
int memo(int ind,int sum,vector<int>&num,vector<vector<int>>&dp){
    if(ind==0){
        if(sum==0 && num[0]==0){
            return 2;
        }
        if(sum==0 || sum==num[0]){
            return 1;
        }
        return 0;
    }
    if(dp[ind][sum]!=-1){
        return dp[ind][sum];
    }
    int notTake=memo(ind-1,sum,num,dp);
    int take=0;
    if(num[ind]<=sum){
        take=memo(ind-1,sum-num[ind],num,dp);
    }
    return dp[ind][sum]=(take+notTake)%mod;
}

int findWays(vector<int>&num,int target){
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return memo(n-1,target,num,dp);
}

int countPartitions(int n,int d,vector<int>&arr){
    int totalSum=0;
    for(auto&it:arr){
        totalSum+=it;
    }

    if(totalSum-d<0 || (totalSum-d)%2){
        return 0;
    }
    return findWays(arr,(totalSum-d)/2);
}