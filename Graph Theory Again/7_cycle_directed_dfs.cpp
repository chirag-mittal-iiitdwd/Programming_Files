#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool helper(vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&dfsVis,int i){
        visited[i]=true;
        dfsVis[i]=true;

        for(auto&it:adj[i]){
            if(!visited[it]){
                if(helper(adj,visited,dfsVis,it)){
                    return true;
                }
            }
            else if(dfsVis[it]){
                return true;
            }
        }

        dfsVis[i]=false;
        return true;
    }
    public:
    bool hasCycle(vector<vector<int>>&adj,int n){
        vector<bool>visited(n+1,false);
        vector<bool>dfsVis(n+1,false);

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                if(helper(adj,visited,dfsVis,i)){
                    return true;
                }
            }
        }

        return false;
    }
};