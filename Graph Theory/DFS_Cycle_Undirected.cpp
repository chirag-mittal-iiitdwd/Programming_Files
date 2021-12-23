#include<bits/stdc++.h>
using namespace std;

// Node A : which we are going to visit
// Node B : which we are currently on
// Node C : the parent of current node
// The key concept is that if the A!=C,
// then that mean that somebody prior to node B made node A visited and this means that there is a cycle

class Solution{
    bool helper(vector<vector<int>>&adj,vector<int>&visited,int i,int parent){
        visited[i]=1;
        for(auto &it:adj[i]){
            if(!visited[it]){
                if(helper(adj,visited,it,i)){
                    return true;
                }
            }
            else if(it!=parent){
                return true;
            }
        }
        return false;
    }
    public:
    bool dfs(vector<vector<int>>&adj,int n){
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(helper(adj,visited,i,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;

}