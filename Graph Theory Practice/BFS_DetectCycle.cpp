#include<bits/stdc++.h>
using namespace std;

bool bfsCycle(vector<int>&visited,vector<vector<int>>adj,int i){
    queue<pair<int,int>>q;
    q.push({i,-1});
    visited[i]=1;
    while(!q.empty()){
        int top=q.front().first;
        int prev=q.front().second;
        q.pop();
        for(auto it:adj[top]){
            if(!visited[it]){
                q.push({it,top});
                visited[it]=1;
            }
            else{
                if(it!=prev){
                    return true;
                }
            }
        }
    }
    return false;
}

// Time Complexity: O(N), N is number of nodes
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
            ans=bfsCycle(visited,adj,i);
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