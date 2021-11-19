#include<bits/stdc++.h>
using namespace std;

bool dfsCycle(vector<vector<int>>adj,int i,vector<int>&color){
    for(auto it:adj[i]){
        if(color[it]==-1){
            color[it]=1-color[i];
            if(!dfsCycle(adj,it,color)){
                return false;
            }
        }
        else if(color[i]==color[it]){
            return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>color(n+1,-1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans=false;
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            color[i]=0;
            ans=dfsCycle(adj,i,color);
            if(ans){
                break;
            }
        }
    }
    if(ans){
        cout<<"BIPARTITE\n";
    }
    else{
        cout<<"NOT BIPARTITE\n";
    }
}