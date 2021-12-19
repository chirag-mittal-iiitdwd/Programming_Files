#include<bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution {
    int binarySearch(vector<int>&nums,int l,int r,int&target){
        if(l>r){
            return -1;
        }
        int mid=l+((r-l)/2);
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            return binarySearch(nums,l,mid-1,target);
        }
        else{
            return binarySearch(nums,mid+1,r,target);
        }
    }
    public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0){
            return {-1,-1};
        }
        else if(n==1 && nums[0]==target){
            return {0,0};
        }
        else if(n==1 && nums[0]!=target){
            return {-1,-1};
        }
        else{
            int pos=binarySearch(nums,0,n-1,target);
            if(pos==-1){
                return {-1,-1};
            }
            else{
                vector<int>ans;
                int i=pos-1;
                while(i>=0 && nums[i]==target){
                    i--;
                }
                ans.push_back(i+1);
                i=pos+1;
                while(i<n && nums[i]==target){
                    i++;
                }
                ans.push_back(i-1);
                return ans;
            }
        }
    }
};

class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int an=-1;
        while(s<=e){
            if(nums[mid]==target){
                an=mid;
                e=mid-1;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        ans.push_back(an);
        
        s=0;
        e=nums.size()-1;
        an=-1;
        mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                an=mid;
                s=mid+1;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
         ans.push_back(an);
        return ans;
    }
};