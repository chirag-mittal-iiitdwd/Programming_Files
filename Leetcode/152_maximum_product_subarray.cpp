#include<bits/stdc++.h>
using namespace std;

class Solution {
    int helper(vector<int>&nums,int i,int curProd,int n){
        if(i==n){
            return curProd;
        }

        int included=helper(nums,i+1,curProd*nums[i],n);
        int notIncluded=helper(nums,i+1,curProd,n);
        return max(included,notIncluded);
    }
public:
    int maxProduct(vector<int>& nums) {
        return helper(nums,0,1,nums.size());
    }
};