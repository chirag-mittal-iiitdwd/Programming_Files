#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool helper(vector<vector<int>>&adj,vector<int>&vis,vector<int>&dfsVis,int&i){
        vis[i]=1;
        dfsVis[i]=1;
        for(auto &it:adj[i]){
            if(!vis[i]){
                if(helper(adj,vis,dfsVis,it)){
                    return true;
                }
            }
            else if(dfsVis[i]){
                return true;
            }
        }
        dfsVis[i]=0;
        return false;
    }
    public:
    bool dfs(vector<vector<int>>&adj,int&n){
        vector<int>vis(n,0);
        vector<int>dfsVis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(helper(adj,vis,dfsVis,i)){
                    return true;
                }
            }
        }
        return false;
    }
};