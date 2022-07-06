#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size(),backSum=0;
        vector<int>ans;

        for(int i=n-1;i>=0;i--){
            backSum+=nums[i];
            sum-=nums[i];
            ans.push_back(nums[i]);
            if(backSum>sum){
                break;
            }
        }

        return ans;
    }
};