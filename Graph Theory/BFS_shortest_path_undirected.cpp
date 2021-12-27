#include<bits/stdc++.h>
using namespace std;

/*
    This is for UNIT Weights Only
    Create a distance array and mark everything as INT_MAX
    Create a queue and this will always store the nodes
    push push src mark dist[src]=0
*/

class Solution{
    public:
    vector<int>distance(vector<vector<int>>&adj,int n,int src){
        vector<int>dist(n,INT_MAX);
        queue<int>q;
        q.push(src);
        dist[src]=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto &it:adj[top]){
                if(dist[top]+1<dist[it]){
                    dist[it]=1+dist[top];
                    q.push(it);
                }
            }
        }
    }
};