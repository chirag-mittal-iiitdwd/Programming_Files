#include<bits/stdc++.h>
using namespace std;

bool bfsBipartite(vector<vector<int>>adj,vector<int>&color,int i){
    queue<int>q;
    q.push(i);
    color[i]=0;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(auto it:adj[i]){
            if(color[it]==-1){
                color[it]=1-color[i];
                q.push(it);
            }
            else if(color[it]==color[top]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    vector<int>color(n+1,-1);
    bool ans=false;
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            ans=bfsBipartite(adj,color,i);
            if(ans){
                break;
            }
        }
    }
    if(ans){
        cout<<"Bipartite\n";
    }
    else{
        cout<<"Not Bipartite\n";
    }
}


// Not Bipartite
// 8 8
// 1 2
// 2 3
// 3 4
// 2 8
// 8 5
// 4 5
// 5 6
// 6 7

