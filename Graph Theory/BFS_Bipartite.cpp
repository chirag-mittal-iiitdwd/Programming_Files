// The graph should not have Odd cycle for it to a bipartite

#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool helper(int i,vector<vector<int>>&adj,vector<int>&color){
        queue<int>q;
        q.push(i);
        if(color[i]==-1){
            color[i]=1;
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &it:adj[node]){
                if(color[it]==-1){
                    color[it]=1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    public:
    bool isBipartite(vector<vector<int>>&adj,int n){
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!helper(i,adj,color)){
                    return false;
                }
            }
        }
        return true;
    }
};
