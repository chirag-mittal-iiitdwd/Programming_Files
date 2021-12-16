#include<bits/stdc++.h>
using namespace std;

class Solution{
    void dfsHelper(vector<vector<int>>&adj,vector<int>&visited,vector<int>&dfsArr,int&i){
        dfsArr.push_back(i);
        visited[i]=1;
        for(auto &it:adj[i]){
            if(!visited[it]){
                dfsHelper(adj,visited,dfsArr,it);
            }
        }
    }
    public:
    vector<int>dfs(vector<vector<int>>&adj,int&n){
        vector<int>visited(n+1,0);
        vector<int>dfsArr;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfsHelper(adj,visited,dfsArr,i);
            }
        }
        return dfsArr;
    }
};

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

    Solution obj;
    vector<int>dfs=obj.dfs(adj,n);
    for(auto &it:dfs){
        cout<<it<<" ";
    }
    cout<<endl;
}