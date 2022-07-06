#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxi=INT_MIN,n=nums.size(),curSum=0;
        vector<int>mp(10001,-1);
        int l=0,r=0;

        while(r<n){
            if(mp[nums[r]]!=-1){
                int idx=mp[nums[r]];
                while(l<=idx){
                    mp[nums[l]]=-1;
                    curSum-=nums[l];
                    l++;
                }
            }
            curSum+=nums[r];
            mp[nums[r]]=r;
            maxi=max(maxi,curSum);
            r++;
        }

        return maxi;
    }
};