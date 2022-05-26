#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);
        int size=edges.size();

        for(int i=0;i<size;i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        priority_queue<pair<double,int>>q;
        vector<double>dist(n,(double)0.0);
        dist[start]=(double)1.0;

        q.push({(double)1.0,start});
        while(!q.empty()){
            double dis=q.top().first;
            int prev=q.top().second;
            q.pop();

            for(auto&it:adj[prev]){
                if(dist[it.first]<it.second*dis){
                    dist[it.first]=it.second*dis;
                    q.push({dist[it.first],it.first});
                }
            }
        }

        return dist[end];
    }
};