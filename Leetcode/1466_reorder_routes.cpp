#include<bits/stdc++.h>
using namespace std;

class Solution {
    void bfs(vector<vector<int>>&adj,vector<int>&visited){
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto&it:adj[top]){
                if(!visited[it]){

                }
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj;

        for(auto&it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool>visited(n,false);
    }
};
