#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum-x;

        if(target==0){
            return nums.size();
        }
        if(target<0){
            return -1;
        }

        int left=0,sum=0,ans=-1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>target){
                sum-=nums[left++];
            }

            if(target==sum){
                ans=max(ans,i-left+1);
            }
        }
        return ans==-1?-1:nums.size()-ans;
    }
};