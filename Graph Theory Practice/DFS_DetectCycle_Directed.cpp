#include<bits/stdc++.h>
using namespace std;

bool dfsCycle(vector<vector<int>>adj,vector<int>&visited,vector<int>&dfsVisited,int i){
    dfsVisited[i]=1;
    visited[i]=1;
    for(auto it:adj[i]){
        if(!visited[it]){
            if(dfsCycle(adj,visited,dfsVisited,it)){
                return true;
            }
        }
        else if(dfsVisited[it]){
            return true;
        }
    }
    dfsVisited[i]=0;
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>visited(n+1,0);
    vector<int>dfsVisited(n+1,0);
    cout<<"The edge is from first input to second"<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool ans=false;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            ans=dfsCycle(adj,visited,dfsVisited,i);
            if(ans){
                break;
            }
        }
    }
    if(ans){
        cout<<"Has Cycle\n";
    }
    else{
        cout<<"Does not have cycle\n";
    }
}

// No cycle
// 9 9
// 1 2
// 2 3
// 3 4
// 4 5
// 3 6
// 6 5
// 7 2
// 7 8
// 8 9

// Has Cycle
// 9 10
// 1 2
// 2 3
// 3 4
// 4 5
// 3 6
// 6 5
// 7 2
// 7 8
// 8 9
// 9 7