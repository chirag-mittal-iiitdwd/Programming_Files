#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool helper(vector<vector<int>>&adj,vector<int>&visited,int i){
        queue<pair<int,int>>q;
        q.push({i,-1});
        visited[i]=1;

        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();

            for(auto&it:adj[node]){
                if(!visited[it]){
                    q.push({it,node});
                }
                else if(par!=it){
                    return true;
                }
            }
        }
        return false;
    }
    public:
    bool isCycle(vector<vector<int>>&adj,int n){
        vector<int>visited(n+1);

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                if(helper(adj,visited,i)){
                    return true;
                }
            }
        }
        return false;
    }
};