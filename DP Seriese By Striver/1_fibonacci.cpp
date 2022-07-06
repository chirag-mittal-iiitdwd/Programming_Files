#include<bits/stdc++.h>
using namespace std;

int recursiveSol(int n){
    if(n==0 || n==1){
        return n;
    }
    return recursiveSol(n-1)+recursiveSol(n-2);
}

int dpTopDown(int n,vector<int>&dp){
    if(n==0 || n==1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] = dpTopDown(n-1,dp)+dpTopDown(n-2,dp);
}

int dpBottomUp(int n){
    vector<int>dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int dpConstantSpace(int n){
    if(n==0 || n==1){
        return n;
    }
    int prev2=0,prev=1;
    for(int i=2;i<=n;i++){
        int cur=prev+prev2;
        prev2=prev;
        prev=cur;
    }
    return prev;
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<recursiveSol(n)<<endl;
    cout<<dpTopDown(n,dp)<<endl;
    cout<<dpBottomUp(n)<<endl;
    cout<<dpConstantSpace(n)<<endl;
}