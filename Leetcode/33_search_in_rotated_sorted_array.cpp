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


// class sol2{
//     int findPivot(vector<int>&nums,int target,int l,int r){
//         if(l>r){
//             return -1;
//         }
//         if(l==r){
//             return l;
//         }
//         int mid=(l+r)/2;
//         if(nums[mid]==target){
//             return mid;
//         }
//         else if(mid<r && nums[mid+1]<nums[mid]){
//             return mid;
//         }
//         else if(mid>l && nums[mid-1]>nums[mid]){
//             return mid-1;
//         }
//         else if(nums[l]<nums[mid]){
//         // First part is sorted and the pivot is in second part 
//             l=mid+1;
//         }
//         else{
//             r=mid-1;
//         }
//     }
//     public:
//     int search(vector<int>&nums,int target){
//         int n=nums.size();
//         int pivot=findPivot(nums,target,0,n-1);

//         if(nums[pivot]==target){
//             return pivot;
//         }
//         else if(nums[0]>target){
//             cout<<"Second Half\n"<<endl;
//         }
//     }
// };

class Solution {
    int binary_search(vector<int>&nums,int l,int r,int target){
        if(l>r){
            return -1;
        }
        int mid=(l+r)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            return binary_search(nums,l,mid-1,target);
        }
        return binary_search(nums,mid+1,r,target);
    }
    int findPivot(vector<int>&nums,int l,int r){
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
        else if(l<mid && nums[mid-1]>nums[mid]){
            return mid-1;
        }
        else if(nums[l]>nums[mid]){
            return findPivot(nums,l,mid-1);
        }
        return findPivot(nums,mid+1,r);
    }
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int pivot=findPivot(nums,l,r);

        if(nums[pivot]==target){
            return pivot;
        }
        else if(nums[0]>target){
            return binary_search(nums,pivot+1,r,target);
        }
        return binary_search(nums,0,pivot,target);
    }
};