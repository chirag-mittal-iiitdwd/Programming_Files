#include<bits/stdc++.h>
using namespace std;

class Solution {
    void recur(set<vector<int>>&s,int i,vector<int>&nums){
        if(i>=nums.size()){
            s.insert(nums);
            return;
        }

        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            recur(s,i+1,nums);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        for(auto &it:s){
            ans.push_back(it);
        }
        return ans;
    }
};