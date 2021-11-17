#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>&dfsArr,int i,vector<vector<int>>adj,vector<int>&visited){
    visited[i]=1;
    dfsArr.push_back(i);
    for(auto it:adj[i]){
        if(!visited[it]){
            dfs(dfsArr,it,adj,visited);
        }
    }
}

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
    vector<int>dfsArr;
    vector<int>visited(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(dfsArr,i,adj,visited);
        }
    }

    for(auto it:dfsArr){
        cout<<it<<" ";
    }
    cout<<endl;
}

// Input:
// 7 6
// 1 2
// 2 4
// 2 7
// 7 6
// 4 6
// 3 5

// Output :
// 1 2 4 6 7 3 5