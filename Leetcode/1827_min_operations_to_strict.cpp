#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),curMax=INT_MIN,ans=0;

        for(int i=0;i<n;i++){
            if(curMax<nums[i]){
                curMax=nums[i];
            }
            else{
                int diff=abs(curMax-nums[i])+1;
                ans+=diff;
                curMax+=diff;
                nums[i]+=diff;
            }
        }

        return ans;
    }
};