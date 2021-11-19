#include<bits/stdc++.h>
using namespace std;

bool dfsCycle(vector<int>&visited,vector<vector<int>>adj,int i,int parent){
    visited[i]=1;
    for(auto it:adj[i]){
        if(!visited[it]){
            if(dfsCycle(visited,adj,it,i)){
                return true;
            }
        }
        else{
            if(parent!=it){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>visited(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans=false;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            ans=dfsCycle(visited,adj,i,-1);
            if(ans){
                break;
            }
        }
    }
    if(ans){
        cout<<"Cyclic\n";
    }
    else{
        cout<<"Not Cyclic\n";
    }
}