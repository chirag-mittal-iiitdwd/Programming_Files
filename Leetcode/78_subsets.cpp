#include<bits/stdc++.h>
using namespace std;

class Solution {
    void helper(set<vector<int>>&s,vector<int>&x,vector<int>&nums,int i){
        
        for(int j=i;j<nums.size();j++){
            x.push_back(nums[j]);
            helper(s,x,nums,j+1);
            x.pop_back();
            helper(s,x,nums,j+1);
        }
        s.insert(x);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        vector<int>x;
        helper(s,x,nums,0);
        for(auto&it:s){
            ans.push_back(it);
        }
        return ans;
    }
};

class Solution{
    void helper(vector<int>&nums,int idx,vector<int>&x,vector<vector<int>>&ans){
        if(idx>=nums.size()){
            ans.push_back(x);
            return;
        }
        helper(nums,idx+1,x,ans);
        x.push_back(nums[idx]);
        helper(nums,idx+1,x,ans);
        x.pop_back();
    }
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int idx=0;
        vector<int>x;
        helper(nums,idx,x,ans);
        return ans;
    }
};