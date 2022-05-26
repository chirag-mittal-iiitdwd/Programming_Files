#include<bits/stdc++.h>
using namespace std;

class Solution {
    void bfs(vector<vector<int>>&adj,vector<bool>&visited,int i){
        queue<int>q;
        q.push(i);
        visited[i]=true;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto&it:adj[top]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push(it);
                }
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cables=connections.size();
        if(cables<n-1){
            return -1;
        }

        vector<vector<int>>adj(n);
        for(int i=0;i<cables;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool>visited(n,false);

        int ans=0;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                bfs(adj,visited,i);
            }
        }

        return ans;
    }
};