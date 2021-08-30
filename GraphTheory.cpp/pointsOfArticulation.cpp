/*
    The articulation points are the nodes which when taken out leads to
    two or more components
    condition : low [it] >= time [node] && parent != -1
    There is grater than equal to because we must reach the other end of 
    the node
*/
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int parent,vector<int>&vis,vector<int>&time,vector<int>&low,int &timer,vector<int>adj[],vector<int>&isArti){
    vis[node]=1;
    time[node]=low[node]=timer++;
    int child=0;
    for(auto it:adj[node]){
        if(it==parent){
            continue;
        }
        if(!vis[it]){
            dfs(it,node,vis,time,low,timer,adj,isArti);
            low[node]=min(low[node],low[it]);
            child++;
            if(low[it]>=time[node] && parent!=-1){
                isArti[node]=1;
            }
        }
        else{
            low[node]=min(low[node],time[it]);
        }
    }

    // This case is for the starting parent
    if(parent==-1 && child>1){
        isArti[node]=1;
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
        adj[v].push_back(u);
    }
    vector<int>time(n,-1);
    vector<int>low(n,-1);
    vector<int>vis(n,0);
    vector<int>isArti(n,0);
    int timer=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,vis,time,low,timer,adj,isArti);
        }
    }
    for(int i=0;i<n;i++){
        if(isArti[i]==1){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}