/*
    Declare a distance array similar to number of nodes
    mark at as INT_MAX
    make queue and insert the source and mark dis[node]=0
    now pop the element from queue and check adj nodes do this for all nodes
    and keep increasing distance and also compare and keep the shortest distance

    we are using BFS because it visits the nodes in sequential manner 
*/

#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],int n,int src){
    int dist[n];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    queue<int>q;
    dist[src]=0;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(adj,n,0);
}