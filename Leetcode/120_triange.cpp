#include<bits/stdc++.h>
using namespace std;

class Solution {
    void helper(vector<vector<int>>&triangle,int&ans,int curSum,int nxtRow,int prevCol){
        if(nxtRow==triangle.size()){
            ans=min(ans,curSum);
            return;
        }

        helper(triangle,ans,curSum+triangle[nxtRow][prevCol],nxtRow+1,prevCol);
        helper(triangle,ans,curSum+triangle[nxtRow][prevCol+1],nxtRow+1,prevCol+1);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int curSum=triangle[0][0],nxtRow=1,prevCol=0,ans=INT_MAX;
        helper(triangle,ans,curSum,nxtRow,prevCol);
        return ans;
    }
};


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>dp(triangle.back());

        for(int layer=n-2;layer>=0;layer--){
            for(int i=0;i<=layer;i++){
                dp[i]=min(dp[i],dp[i+1])+triangle[layer][i];
            }
        }

        return dp[0];
    }
};