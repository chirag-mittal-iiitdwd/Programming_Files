#include<bits/stdc++.h>
using namespace std;

class Solution {
    int helper(vector<int>&nums,int start,int end,int n){
        while(start<=end){
            int mid=(start+end)/2;
            if(mid+1<n && nums[mid]>nums[mid+1]){
                return nums[mid];
            }
            else if(mid-1>=0 && nums[mid-1]>nums[mid]){
                return nums[mid-1];
            }
            else if(nums[start]>nums[mid]){
                return helper(nums,start,mid-1,n);
            }
            return helper(nums,mid+1,end,n);
        }
    }
public:
    int findMin(vector<int>& nums) {
        return helper(nums,0,nums.size()-1,nums.size());
    }
};