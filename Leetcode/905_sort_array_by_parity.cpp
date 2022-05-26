#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size(),i=0,j=0;

        while(i<n && j<n){
            if((nums[i]%2)!=0){
                i++;
            }
            else{
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }

        return nums;
    }
};