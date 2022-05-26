#include<bits/stdc++.h>
using namespace std; 

class Solution {
    // void dfs(vector<int>&dist,int src,vector<vector<int>>&adj){
    //     dist
    // }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);

        for(auto&it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>dist(n,INT_MAX);
        queue<int>q;
        q.push(source);
        dist[source]=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto&it:adj[top]){
                if(dist[top]+1<dist[it]){
                    dist[it]=dist[top]+1;
                    q.push(it);
                }
            }
        }

        if(dist[destination]==INT_MAX){
            return false;
        }
        return true;
    }
};