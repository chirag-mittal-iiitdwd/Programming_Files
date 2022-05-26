#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<pair<int,int>>>&adj,int k,int curAns,vector<int>&distance){
        if(curAns<distance[k]){
            distance[k]=curAns;
        }
        else{
            return;
        }
        
        for(auto&it:adj[k]){
            // distance[it.first]=it.second+curSum;
            dfs(adj,it.first,curAns+it.second,distance);
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto&it:times){
            adj[it[0]-1].push_back({it[1]-1,it[2]});
        }
        if(adj[k-1].size()==0){
            return -1;
        }
        
        vector<int>distance(n,INT_MAX);
        dfs(adj,k-1,0,distance);

        int ans=0;
        for(auto&it:distance){
            ans=max(ans,it);
        }

        return ans==INT_MAX?-1:ans;
    }
};