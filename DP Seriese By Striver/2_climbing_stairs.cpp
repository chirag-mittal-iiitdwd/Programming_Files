#include<bits/stdc++.h>
using namespace std;

int recursive(int n,int iter){
    if(iter==n){
        return 1;
    }
    if(iter>n){
        return 0;
    }
    return recursive(n,iter+1)+recursive(n,iter+2);
}

int dpSol1(int n,vector<int>&dp,int iter){
    if(iter>=n){
        return 1;
    }
    if(iter>n){
        return 0;
    }
    if(dp[iter]!=-1){
        return dp[iter];
    }
    return dp[iter]=dpSol1(n,dp,iter+1)+dpSol1(n,dp,iter+2);
}