#include <bits/stdc++.h>
using namespace std;
bool bfs(int s, int V, vector<int> adj[], vector<int> &visited){
    vector<int> parent(V, -1);

    // Create a queue for BFS
    queue<pair<int, int>> q;

    visited[s] = true;
    q.push({s, -1});

    while (!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();

        for (auto it : adj[node]){
            if (!visited[it]){
                visited[it] = true;
                q.push({it, node});
            }
            else if (par != it)
                return true;
        }
    }
    return false;
}
// { Driver Code Starts.
int main(){
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> visited(V + 1, 0);
    vector<int> bfsArr;
    bool answer;
    for (int i = 1; i <= V; i++){
        if (visited[i] == 0){
            answer = bfs(i, V, adj, visited);
            if (answer){
                break;
            }
        }
    }

    if (answer){
        cout << "Cycle Detected\n";
    }
    else{
        cout << "Cycle not detected\n";
    }

    return 0;
}