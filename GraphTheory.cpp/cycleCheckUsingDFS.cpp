#include<bits/stdc++.h>
using namespace std;
bool dfsCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1; 
        for(auto it: adj[node]) {
            if(!vis[it]) {
                // If somewhere deeper returns a true than this must also return true
                if(dfsCycle(it, node, vis, adj)) 
                    return true; 
            }

            // the element behid the current and next if they are not equal than somebody 
            // must have visited it previiously indicating a cycle
            else if(it!=parent) 
                return true; 
        }
        
        return false; 
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    vector<int> visited(n+1,0);
    vector<int> bfsArr;
    bool answer;
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            answer=dfsCycle(i,-1,visited,adj);
            if(answer){
                break;
            }
        }
    }
    if(answer){
        cout<<"Cycle Detected\n";
    }
    else{
        cout<<"Cycle not det ected\n";
    }
}
