#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        int n=nums.size();
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(n==k){
            return totalSum;
        }

        int win=n-k;
        int mini=INT_MAX,sum=0;
        for(int i=0;i<win;i++){
            sum+=nums[i];
        }
        mini=min(mini,sum);

        for(int i=1;i<=n-win;i++){
            sum-=nums[i-1];
            sum+=nums[win+i-1];
            mini=min(mini,sum);
        }
        return totalSum-mini;
    }
};