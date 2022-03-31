// MinHeap (dist,node)
// diatance array

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int>minDistance(vector<vector<int>>&adj,int src,int n){
        vector<int>distance(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        distance[src]=0;
        q.push({0,src});

        while(!q.empty()){
            int node=q.top().second;
            int dist=q.top().first;
            q.pop();

            for(auto&it:adj[node]){
                if(distance[node]+dist<distance[it]){
                    distance[it]=distance[node]+it;
                    q.push({distance[it],it});
                }
            }
        }

        return distance;
    }
};