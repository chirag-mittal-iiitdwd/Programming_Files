#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool helper(vector<vector<int>>&adj,vector<int>&color,int i){
        queue<int>q;
        color[i]=1;
        q.push(i);

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto&it:adj[node]){
                if(color[it]==-1){
                    q.push(it);
                    color[it]=1-color[node];
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
        vector<int>color(n+1,-1);

        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!helper(adj,color,i)){
                    return false;
                }
            }
        }
        return true;
    }
};