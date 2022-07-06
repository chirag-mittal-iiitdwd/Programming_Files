#include<bits/stdc++.h>
using namespace std;

int recursion(int n,vector<int>&wt,vector<int>&val,int curVal,int cap){
    if(n==0){
        if(cap>=wt[0]){
            return val[0];
        }
        return 0;
    }

    int notTake=recursion(n-1,wt,val,curVal,cap);
    int take=0;
    if(wt[n]<=cap){
        take=recursion(n-1,wt,val,curVal+val[n],cap-wt[n])+val[n];
    }
    return max(take,notTake);
}

int memo(int n,vector<int>&wt,vector<int>&val,int cap,vector<vector<int>>&dp){
    if(n==0){
        if(cap>=wt[0]){
            return val[0];
        }
        return 0;
    }

    if(dp[n][cap]!=-1){
        return dp[n][cap];
    }

    int notTake=memo(n-1,wt,val,cap,dp);
    int take=0;
    if(wt[n]<=cap){
        take=memo(n-1,wt,val,cap-wt[n],dp)+val[n];
    }
    return dp[n][cap] = max(take,notTake);
}

int tabulation(vector<int>&wt,vector<int>&val,int n,int maxWeight){
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));

    for(int w=wt[0];w<=maxWeight;w++){
        dp[0][w]=val[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=maxWeight;w++){
            int notTake=dp[ind-1][w];
            int take=INT_MIN;
            if(wt[ind]<=w){
                take=val[ind]+dp[ind-1][w-wt[ind]];
            }
            dp[ind][w]=max(take,notTake);
        }
    }

    return dp[n-1][maxWeight];
}

int spaceOpt(vector<int>&wt,vector<int>&val,int n,int maxWeight){
    vector<int>prev(maxWeight+1,0),cur(maxWeight+1,0);

    for(int w=wt[0];w<=maxWeight;w++){
        prev[w]=val[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=maxWeight;w++){
            int notTake=prev[w];
            int take=INT_MIN;
            if(wt[ind]<=w){
                take=val[ind]+prev[w-wt[ind]];
            }
            cur[w]=max(take,notTake);
        }
        prev=cur;
    }

    return prev[maxWeight];
}