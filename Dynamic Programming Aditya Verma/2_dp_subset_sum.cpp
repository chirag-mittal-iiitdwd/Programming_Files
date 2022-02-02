#include<bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int>arr,int n,int sum,vector<vector<bool>>dp){
    if(sum==0){
        return true;
    }
    if(n==0){
        return false;
    }
    if(arr[n-1]<=sum){
        dp[n][sum]= subsetSum(arr,n-1,sum-arr[n-1],dp)||subsetSum(arr,n-1,sum,dp);
    }
    else{
        dp[n][sum]= subsetSum(arr,n-1,sum,dp);
    }
    return dp[n][sum];
}

int main(){
    vector<int>arr={3,34,4,12,5,2};
    int sum=9;
    int n=arr.size();
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1));

    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=0;i<=sum;i++){
        dp[0][i]=false;
    }

    cout<<subsetSum(arr,n,sum,dp)<<endl;
}