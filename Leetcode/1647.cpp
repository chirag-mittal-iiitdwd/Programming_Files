#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int>nums(26,0);
        for(auto&it:s){
            nums[it-'a']++;
        }
        sort(nums.begin(),nums.end(),greater<int>());

        int keep=0,prev=INT_MAX;
        for(int it:nums){
            if(!it || !prev){
                break;
            }

            prev=min(it,prev-1);
            keep+=prev;
        }

        int ans=s.size()-keep;
        return ans;
    }
};