#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),r=0,l=0,ans=INT_MAX,sum=0;

        while(r<n){
            sum+=nums[r++];
            while(sum>=target){
                ans=min(ans,r-l);
                sum-=nums[l++];
            }
        }

        return ans==INT_MAX?0:ans;
    }
};


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),len=INT_MAX;

        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }

        for(int i=n-1;i>=0 && nums[i]>=target;i--){
            int j=upper_bound(nums.begin(),nums.end(),nums[i]-target)-nums.begin();
            len=min(len,i-j+1);
        }
        return len==INT_MAX?0:len;
    }
};