#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool>mp1;

        for(auto&it:nums1){
            mp1[it]=true;
        }

        vector<int>ans;
        for(auto&it:nums2){
            if(mp1[it]==true){
                ans.push_back(it);
                mp1[it]=false;
            }
        }
        return ans;
    }
};
