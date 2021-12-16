#include<bits/stdc++.h>
using namespace std;

class Solution{
    void bfsHelper(vector<int>&visited,vector<vector<int>>&adj,int&n,int&i,vector<int>&bfsArr){
        queue<int>q;
        q.push(i);
        visited[i]=1;
        while(!q.empty()){
            int cur=q.front();
            bfsArr.push_back(cur);
            q.pop();
            for(auto &it:adj[cur]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
    }
    public:
    vector<int>bfs(vector<vector<int>>adj,int n){
        vector<int>visited(n+1,0);
        vector<int>bfsArr;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                bfsHelper(visited,adj,n,i,bfsArr);
            }
        }
        return bfsArr;
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
    vector<int>bfs=obj.bfs(adj,n);
    for(auto &it:bfs){
        cout<<it<<" ";
    }
    cout<<endl;
}
