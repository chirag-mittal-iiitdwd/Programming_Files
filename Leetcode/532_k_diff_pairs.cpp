#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        set<int>s;
        unordered_map<int,int>mp;

        for(auto&it:nums){
            mp[it]++;
        }

        for(auto&it:nums){
            if(mp[k-it]!=0){
                s.insert(it);
                s.insert(k-it);
            }
        }

        return s.size()-1;
    }
};