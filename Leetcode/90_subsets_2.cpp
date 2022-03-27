#include<bits/stdc++.h>
using namespace std;

class Solution {
    void helper(vector<int>subset,set<vector<int>>&subsets,vector<int>nums,int begin){
        subsets.insert(subset);
        for(int i=begin;i<nums.size();i++){
            subset.push_back(nums[i]);
            helper(subset,subsets,nums,i+1);
            subset.pop_back();
            helper(subset,subsets,nums,i+1);
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>sub;
        sort(nums.begin(),nums.end());
        helper({},sub,nums,0);
        vector<vector<int>>ans;

        for(auto&it:sub){
            vector<int>subset;
            for(auto&i:it){
                subset.push_back(i);
            }
            ans.push_back(subset);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        vector<int> subset;
        subsetsWithDupWorker(nums, subsets, subset, 0);
        return subsets;
    }
private:
    void subsetsWithDupWorker(const vector<int>& nums, vector<vector<int>>& subsets, vector<int>& subset, int begin) {
        subsets.push_back(subset);
        for (int i = begin; i < nums.size(); i++) {
            if (i != begin && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            subsetsWithDupWorker(nums, subsets, subset, i+1);
            subset.pop_back();
        }
    }
};