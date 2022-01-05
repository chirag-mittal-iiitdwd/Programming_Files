#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
    int helper(int n,vector<int>&dp){
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=helper(n-1,dp)+helper(n-2,dp)+helper(n-3,dp);
        return dp[n];
    }
public:
    int tribonacci(int n) {
        if(n==1 || n==0){
            return n;
        }
        else if(n==2){
            return 1;
        }
        else{
            vector<int>dp(n+1,-1);
            dp[0]=0;
            dp[1]=1;
            dp[2]=1;
            return helper(n,dp);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}