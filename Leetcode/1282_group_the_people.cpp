#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int,int>>v;
        int n=groupSizes.size();

        for(int i=0;i<n;i++){
            v.push_back({groupSizes[i],i});
        }

        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
            return a.first<b.first;
        });

        vector<vector<int>>ans;
        int i=0;
        vector<int>temp;
        while(i<n){
            temp.push_back(v[i].second);
            if(temp.size()==v[i].first){
                ans.push_back(temp);
                temp.clear();
            }
            i++;
        }
        return ans;
    }
};