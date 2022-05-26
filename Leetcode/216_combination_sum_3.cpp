#include<bits/stdc++.h>
using namespace std;

class Solution {
    void helper(set<vector<int>>&ans,int curSum,int k,int n,vector<int>curComb,int j){
        if(curSum>n){
            return;
        }
        if(curComb.size()==k){
            if(curSum==n){
                ans.insert(curComb);
            }
            return;
        }

        for(int i=j;i<=n;i++){
            curComb.push_back(i);
            helper(ans,curSum+i,k,n,curComb,i+1);
            curComb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>>ans;
        helper(ans,0,k,n,{},1);
        vector<vector<int>>v;
        for(auto&it:ans){
            v.push_back(it);
        }
        return v;
    }
};