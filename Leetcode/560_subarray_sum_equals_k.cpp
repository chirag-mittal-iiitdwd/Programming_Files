#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0,ans=0;
        mp[0]++;

        for(auto&it:nums){
            sum+=it;
            mp[sum]++;
            if(mp[sum-k]!=0){
                ans+=mp[sum-k];
            }
        }
        return ans;   
    }
};