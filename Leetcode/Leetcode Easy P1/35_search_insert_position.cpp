#include<bits/stdc++.h>
using namespace std;

class Solution {
    void binarySearch(int l,int r,vector<int>&nums,int target,int&ans){
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                ans=mid;
                return;
            }
            else if(nums[mid]>target){
                ans=mid;
                binarySearch(l,mid-1,nums,target,ans);
            }
            else{
                ans=mid+1;
                binarySearch(mid+1,r,nums,target,ans);
            }
        }
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        if(nums[n-1]<target){
            return n;
        }
        else if(nums[0]>=target){
            return 0;
        }
        else{
            int ans=-1;
            binarySearch(l,r,nums,target,ans);
            return ans;
        }      
    }
};


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
