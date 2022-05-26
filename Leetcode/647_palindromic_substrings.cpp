#include<bits/stdc++.h>
using namespace std;

class Solution {
    int helper(vector<vector<int>>&dp,int i,int j,string&s){
        if(i>=j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return s[i]==s[j]?helper(dp,i+1,j-1,s):0;
    }
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                cnt+=helper(dp,i,j,s);
            }
        }

        return cnt;
    }
};

class Solution {
    int helper(string s,int i,int j,int n){
        int ans=0;
        while(i>=0 && j<n && s[i]==s[j]){
            ans++;
        }
        return ans;
    }
public:
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;

        for(int i=0;i<n;i++){
            ans+=helper(s,i,i,n);
            ans+=helper(s,i,i+1,n);
        }

        return ans;
    }
};