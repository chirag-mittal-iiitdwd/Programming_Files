#include<bits/stdc++.h>
using namespace std;

class Solution {
    void bfs(vector<vector<int>>&adj,int i,vector<bool>&visited){
        queue<int>q;
        q.push(i);
        visited[i]=true;

        while(!q.empty()){
            int top=q.front();
            q.pop();

            for(auto&it:adj[top]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=true;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool>visited(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(adj,i,visited);
                ans++;
            }
        }

        return ans;
    }
};