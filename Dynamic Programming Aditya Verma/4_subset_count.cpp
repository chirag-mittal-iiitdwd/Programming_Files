#include<bits/stdc++.h>
using namespace std;

int subsetCount(vector<int>arr,int n,int sum,vector<vector<int>>dp){
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }

    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    if(arr[n-1]<=sum){
        dp[n][sum]=subsetCount(arr,n-1,sum-arr[n-1],dp)+subsetCount(arr,n-1,sum,dp);
    }
    else{
        dp[n][sum]=subsetCount(arr,n-1,sum,dp);
    }
    return dp[n][sum];
}

int main(){
    vector<int>arr={};
    int sum=10,n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(sum+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][1]=0;
    }

    cout<<subsetCount(arr,n,sum,dp)<<endl;
}