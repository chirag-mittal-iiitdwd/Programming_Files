#include<bits/stdc++.h>
using namespace std;
class solution{
    void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&storeDfs){
        storeDfs.push_back(node);
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,storeDfs);
            }
        }
    }
    public:
    vector<int>dfsOfGraph(int V,vector<int>adj[]){
        vector<int>storeDfs;
        vector<int>vis(V+1,0);
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,storeDfs);
            }
        }
        return storeDfs;
    }
};

int main(){
    solution* x=new solution();
    int n,m;
    cout<<"Enter number of nodes : ";
    cin>>n;
    cout<<"Enter number of edges : ";
    cin>>m;
    vector<int> a[n+1];
    for(int i=0;i<m;i++){
        cout<<"Enter node neighbours : ";
        int u,v;
        cin>>u>>v;
        a[v].push_back(u);
        a[u].push_back(v);
    }
    vector<int>dfsArr=x->dfsOfGraph(n,a);
    cout<<"The required BFS traversal is : ";
    for(auto it:dfsArr){
        cout<<it<<" ";
    }
    cout<<endl;
}