#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return 0;
        }

        int dp=0;
        int ans=0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp++;
            }
            else{
                dp=0;
            }
            ans+=dp;
        }

        return ans;
    }
};