#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        long long sum=((n)*(n+1))/2;
        for(auto &it:nums){
            sum-=it;
        }
        return sum;
    }
};

class Solution{
    public:
    int missingNumber(vector<int>&nums){
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans^i^nums[i];
        }
        return ans^n;
    }
};