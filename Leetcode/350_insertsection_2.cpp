#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Time : O(max(len,len2)), Space : O(len1)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        unordered_map<int,int>mp1;

        for(auto&it:nums1){
            mp1[it]++;
        }
        
        vector<int>ans;
        for(auto&it:nums2){
            if(mp1[it]!=0){
                ans.push_back(it);
                mp1[it]--;
            }
        }
        return ans;
    }
};