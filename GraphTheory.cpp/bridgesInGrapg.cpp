/*
    Bridges when removed from the graph separate the graph into two parts
    Two arrays
        time of insertion : stores the time during the insertion during DFS
        lowest time : Lowest insertion time among all nodes
        whenever we find a backedge then we replace the low time of that node
        with insertion time of its ancestor
    
                            (node) ----------(node)
                            /      \       |   /
                           /        \    > |  /
                        (node)       \   (node)
                        /    | <      \  
                       /     |         \
                    (node)--(node)      \  
                                      (node)----(node)
                                        /   \   |
                                       /     \  |
                                 --(node)   (node)
                                       \  
                                      (node)
  Back edges can never be bridges                                
*/

// Time complexity = O ( Nodes + Edges )
// Space Complexity = O(2N)
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[]) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++; 
    for(auto it: adj[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj); 
            low[node] = min(low[node], low[it]); 
            if(low[it] > tin[node]) {
                cout << node << " " << it << endl;
            }
            // if it is inserted than low of node will be time of insertion
            // Because time of insertion will be the lowest in that case
        } else {
            low[node] = min(low[node], tin[it]); 
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m; 
    vector<int> adj[n]; 
    for(int i = 0;i<m;i++) {
        int u, v;
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
	
    vector<int> tin(n, -1);
    vector<int> low(n, -1); 
    vector<int> vis(n, 0); 
    int timer = 0; 
    for(int i = 0;i<n;i++) {
        if(!vis[i]) {
            dfs(i, -1, vis, tin, low, timer, adj); 
        }
    }
    
    return 0;
}