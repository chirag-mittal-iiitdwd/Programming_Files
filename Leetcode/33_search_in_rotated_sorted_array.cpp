#include<bits/stdc++.h>
using namespace std;

class Solution {
    int binarySearch(int l,int r,vector<int>&nums,int&key){
        if(l>r){
            return -1;
        }
        int mid=(l+r)/2;
        if(nums[mid]==key){
            return mid;
        }
        else if(nums[mid]<key){
            return binarySearch(mid+1,r,nums,key);
        }
        else{
            return binarySearch(l,mid-1,nums,key);
        }
    }
    int findPivot(vector<int>&nums,int h,int l){
        if(h<l){
            return -1;
        }
        if(h==l){
            return l;
        }
        int mid=(l+h)/2;
        if(mid<h && nums[mid]>nums[mid+1]){
            return mid;
        }
        if(mid>l && nums[mid]<nums[mid-1]){
            return mid-1;
        }
        if(nums[l]>=nums[mid]){
            return findPivot(nums,mid-1,l);
        }
        return findPivot(nums,h,mid+1);
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=findPivot(nums,n-1,0);
        if(pivot==-1){
            return binarySearch(0,n-1,nums,target);
        }
        else if(nums[pivot]==target){
            return pivot;
        }
        else if(nums[0]>target){
            return binarySearch(pivot+1,n-1,nums,target);
        }
        else{
            return binarySearch(0,pivot-1,nums,target);
        }
    }
};