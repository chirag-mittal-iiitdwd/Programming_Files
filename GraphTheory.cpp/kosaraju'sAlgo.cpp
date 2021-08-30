/*
    1. Find the topological sort --> O(N)
    2. Teanspose the graph - reverse the edges --> O(N+E)
    3. DFS according to stack data  --> O(N+E)

    space complexity = O(N+E)+O(N)+O(N)
*/

#include<bits/stdc++.h>
using namespace std;
void dfs(stack<int>&st,int node,vector<int>&vis,vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(st,it,vis,adj);
        }
    }
    st.push(node);
}

void revDFS(int node,vector<int>&vis,vector<int>transpose[]){
    cout<<node<<" ";
    vis[node]=1;
    for(auto it:transpose[node]){
        if(!vis[it]){
            revDFS(it,vis,transpose);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    stack<int>st;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(st,i,vis,adj);
        }
    }

    vector<int>transpose[n];
    for(int i=0;i<n;i++){
        vis[i]=0;

        // Previously there was an edge from i to it now from it to i
        for(auto it:adj[i]){
            transpose[it].push_back(i);
        }
    }

    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            cout<<"SEC : ";
            revDFS(node,vis,transpose);
            cout<<endl;
        }
    }
}