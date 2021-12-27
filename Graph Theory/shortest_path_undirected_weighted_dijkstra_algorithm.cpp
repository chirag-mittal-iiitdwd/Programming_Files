#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int>distance(vector<vector<pair<int,int>>>&adj,int n,int src){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);

        dist[src]=0;
        pq.push({0,src}); // (distance,node)
        while(!pq.empty()){
            int dis=pq.top().first;
            int prev=pq.top().second;
            pq.pop();

            for(auto &it:adj[prev]){
                if(dist[prev]+it.second<dist[it.first]){
                    dist[it.first]=dist[prev]+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }

        return dist;
    }
};