#include<bits/stdc++.h>
using namespace std;

int knapsack01(vector<int>&wt,vector<int>&val,int w,int n,vector<vector<int>>&dp){
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }

    if(wt[n-1]<=w){
        dp[n][w]=max(val[n-1]+knapsack01(wt,val,w-wt[n-1],n-1,dp),knapsack01(wt,val,w,n-1,dp));
    }
    else{
        dp[n][w]=knapsack01(wt,val,w,n-1,dp);
    }
    return dp[n][w];
}

int main(){
    int n,w;
    cin>>n>>w;

    vector<int>wt(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }

    vector<int>val(n);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }

    vector<vector<int>>dp(n+1,vector<int>(w+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=w;i++){
        dp[0][i]=0;
    }

    cout<<knapsack01(wt,val,w,n,dp)<<endl;
}