#include<bits/stdc++.h>
using namespace std;

class Solution {
    // int dp[1001];
    void helper(int&ans,vector<vector<int>>&pairs,int i,int n,int curLen,int curUpper){
        if(i==n){
            ans=max(ans,curLen);
            return;
        }
        
        helper(ans,pairs,i+1,n,curLen,curUpper);
        if(pairs[i][0]>curUpper){
            helper(ans,pairs,i+1,n,curLen+1,pairs[i][1]);
        }
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[&](vector<int>&a,vector<int>&b){
            if(a[0]<b[0]){
                return true;
            }
            return false;
        });

        // memset(dp,-1,sizeof(dp));
        int ans=0;
        helper(ans,pairs,0,pairs.size(),0,-1001);
        return ans;
    }
};

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int cnt = 0;
        for (int i = 0, j = 0; j < pairs.size(); j++) {
            if (j == 0 || pairs[i][1] < pairs[j][0]) {
                cnt++;
                i = j;
            }
        }
        return cnt;
    }

private:
    static bool cmp(vector<int>& a, vector<int>&b) {
        return a[1] < b[1];
    }
};