#include<bits/stdc++.h>
using namespace std;

class Solution {
    int isPossible(vector<int>&nums,int mid,int m){
        int st=1,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mid){
                st++;
                sum=nums[i];
            }
        }
        return st==m;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int r=accumulate(nums.begin(),nums.end(),0);
        int l=*max_element(nums.begin(),nums.end());
        
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(isPossible(nums,mid,m)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;
    }
};