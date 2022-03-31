#include<bits/stdc++.h>
using namespace std;

class Solution{
    void findTopoSort(vector<vector<pair<int,int>>>&adj,int i,stack<int>&st,vector<bool>&visited){
        visited[i]=true;
        for(auto&it:adj[i]){
            if(!visited[it.first]){
                findTopoSort(adj,it.first,st,visited);
            }
        }
        st.push(i);
    }
    public:
    void shortestDistanceDAG(vector<vector<pair<int,int>>>&adj,int src,int n){
        stack<int>st;
        vector<bool>visited(n+1,false);
        vector<int>dist(n+1,INT_MAX);
        dist[src]=0;

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                findTopoSort(adj,i,st,visited);
            }
        }

        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(dist[node]!=INT_MAX){
                for(auto&it:adj[node]){
                    if(dist[node]+it.second<dist[it.first]){
                        dist[it.first]=it.second+dist[node];
                    }
                }
            }
        }

        for(int i=1;i<=n;i++){
            cout<<dist[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
    }


}