#include<bits/stdc++.h>
using namespace std;

// Here we do not bother about other components in the graph as the distance from them will be INF
class Solution{
    public:
    void shortestPath(vector<vector<int>>&adj,int n,int src){
        vector<int>dist(n+1,INT_MAX);
        queue<int>q;
        q.push(src);
        dist[src]=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto&it:adj[node]){
                if(dist[node]+1<dist[it]){
                    q.push(it);
                    dist[it]=1+dist[node];
                }
            }
        }

        for(int i=1;i<=n;i++){
            cout<<dist[i]<<" ";
        }
        cout<<endl;
    }
};