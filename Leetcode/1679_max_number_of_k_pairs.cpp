#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();

        for(auto&it:nums){
            if(it<=k){
                mp[it]++;
            }
        }

        int cnt=0;
        for(auto&it:nums){
            if(it<=k && mp[it-k]!=0){
                mp[it]--;
                mp[it-k]--;
                cnt++;
            }
        }

        return cnt;
    }
};