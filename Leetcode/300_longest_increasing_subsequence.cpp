#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }

        int ans=0;
        for(auto&it:dp){
            ans=max(ans,it);
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),len=1;

        vector<int>temp;
        temp.push_back(nums[0]);

        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
            }
        }

        return len;
    }
};


class Solution{
public:
int lengthOfLIS(vector<int>&nums){
        vector<int> lis;
        for(int i = 0;i<nums.size();i++){
            int ele = nums[i];
            
            int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();
            
            if(idx >= lis.size()) lis.push_back(ele);
            else lis[idx] = ele;
        }
        return lis.size();
    }
};