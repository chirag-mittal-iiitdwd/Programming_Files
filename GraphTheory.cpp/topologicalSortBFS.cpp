/*
    Firstly create an array with indegree
    create a queue
    Push all the elements with indegree 0 into the queue
    Than pop the front of queue and add into ans and check 
    adjacent nodes and reduce their indegree by 1
    again check if is there any node with indegree 0
    repeat this until the queue becomes empty

    Known as : Kahn's Algorithm
*/

#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    vector<int> topoSort(int n,vector<int> adj[]){
        queue<int> q;

        // This will be a zero index based graph
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    solution x;
    vector<int> ans=x.topoSort(n,adj);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<"\n";

    return 0;
}