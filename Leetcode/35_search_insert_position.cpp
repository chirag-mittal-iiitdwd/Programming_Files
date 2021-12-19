#include<bits/stdc++.h>
using namespace std;

class Solution {
    int modifiedBinarySearch(vector<int>&nums,int&target,int l,int r,int&ans){
        if(l>r){
            return -1;
        }
        int mid=l+((r-l)/2);
        if(nums[mid]==target){
            ans=mid;
            return mid;
        }
        else if(nums[mid]<target){
            ans=mid+1;
            return modifiedBinarySearch(nums,target,mid+1,r,ans);
        }
        else{
            return modifiedBinarySearch(nums,target,l,mid-1,ans);
        }
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans=-1;
        int n=nums.size();
        if(nums[n-1]<target){
            return n;
        }
        else if(nums[n-1]==target){
            return n-1;
        }
        else if(nums[0]>=target){
            return 0;
        }
        else{
            modifiedBinarySearch(nums,target,0,n,ans);
        return ans;
        }
    }
};