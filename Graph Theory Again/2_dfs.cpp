#include<bits/stdc++.h>
using namespace std;

class Solution{
    void helper(vector<vector<int>>&adj,vector<int>&visited,vector<int>&dfs,int i){
        dfs.push_back(i);
        visited[i]=1;

        for(auto&it:adj[i]){
            if(!visited[it]){
                helper(adj,visited,dfs,it);
            }
        }
    }
    public:
    vector<int>dfs(vector<vector<int>>&adj,int n){
        vector<int>visited(n+1,0);
        vector<int>dfs;

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                helper(adj,visited,dfs,i);
            }
        }
        return dfs;
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
    vector<int>dfs=obj.dfs(adj,n);

    for(auto&it:dfs){
        cout<<it<<" ";
    }
    cout<<endl;
}