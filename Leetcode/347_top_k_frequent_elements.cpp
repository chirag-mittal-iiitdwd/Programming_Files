#include<bits/stdc++.h>
using namespace std;

struct Comp{
    const bool operator()(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Comp>q;
        map<int,int>mp;

        for(auto&it:nums){
            mp[it]++;
        }

        for(auto&it:mp){
            q.push({it.first,it.second});
        }

        vector<int>ans;
        int i=0;
        while(i<k){
            ans.push_back(q.top().first);
            q.pop();
            i++;
        }
        return ans;
    }
};