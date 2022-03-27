#include<bits/stdc++.h>
using namespace std;

class Solution{
    void helper(vector<vector<int>>&adj,vector<int>&visited,vector<int>&bfs,int i){
        queue<int>q;
        q.push(i);
        visited[i]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto&it:adj[node]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
    }
    public:
    vector<int> bfs(vector<vector<int>>&adj,int n){
        vector<int>visited(n+1,0);
        vector<int>bfs;

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                helper(adj,visited,bfs,i);
            }
        }
        return bfs;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    Solution obj;
    vector<int>bfs=obj.bfs(adj,n);
    for(auto&it:bfs){
        cout<<it<<" ";
    }
    cout<<endl;    
}