#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool bfsHelper(vector<int>&visited,vector<vector<int>>&adj,int&i){
        queue<pair<int,int>>q;
        q.push({i,-1});
        visited[i]=1;
        while(!q.empty()){
            int cur=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto &it:adj[cur]){
                if(!visited[it]){
                    q.push({it,i});
                    visited[it]=1;
                }
                else if(it!=par){
                    return true;
                }
            }
        }
        return false;
    }
    public:
    bool bfs(vector<vector<int>>adj,int n){
        vector<int>visited(n+1,0);
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                flag=bfsHelper(visited,adj,i);
                if(flag){
                    break;
                }
            }
        }
        return flag;
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
    cout<<obj.bfs(adj,n)<<endl;
}
