#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool binary_search(vector<int>&nums,int l,int r,int target){
        if(l>r){
            return false;
        }
        int mid=(l+r)/2;
        if(nums[mid]==target){
            return true;
        }
        if(nums[mid]<target){
            while(mid<r && nums[mid]==nums[mid+1]){
                mid++;
            }
            return binary_search(nums,mid+1,r,target);
        }
        while(mid>l && nums[mid]==nums[mid-1]){
            mid--;
        }
        return binary_search(nums,l,mid-1,target);
    }
    int findPivot(vector<int>&nums,int target,int l,int r){
        if(l>r){
            return -1;
        }
        if(l==r){
            return l;
        }
        int mid=(l+r)/2;
        if(mid<r && nums[mid+1]<nums[mid]){
            return mid;
        }
        else if(mid>l && nums[mid-1]>nums[mid]){
            return mid-1;
        }
        else if(nums[l]<nums[mid]){
            return findPivot(nums,target,mid+1,r);
        }
        return findPivot(nums,target,l,mid-1);
    }
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int pivot=findPivot(nums,target,l,r);

        if(nums[pivot]==target){
            return true;
        }
        return binary_search(nums,l,pivot-1,target)||binary_search(nums,pivot+1,r,target);
    }
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;

        while(left<=right){
            if(nums[right]==target ||nums[left]==target){
                return true;
            }
            else if(nums[left]<target){
                while(left<right && nums[left]==nums[left+1]){
                    left++;
                }
                left++;
            }
            else{
                while(left<right && nums[right]==nums[right-1]){
                    right--;
                }
                right--;
            }
        }
        return false;
    }
};