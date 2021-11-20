/*
    Also known as Kahn's Algo
    Make indegree and mark everything as 0 and count indegree for every node and push
    Make a queue and push nodes with indegree as 0

    now go onn with simple BFS algo and keep on reducing indegree and again push 0 indegree's
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void bfsTopoSort(vector<vector<int>>&adj,queue<int>&q,vector<int>&indegree,vector<int>&topoSort){
        while(!q.empty()){
            int n=q.front();
            q.pop();
            topoSort.push_back(n);
            for(auto &it:adj[n]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    queue<int>q;
    vector<int>indegree(n,0);
    vector<int>topo;
    for(int i=0;i<n;i++){
        for(auto &it:adj[i]){
            indegree[it]++;
        }
    }
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    Solution obj;
    obj.bfsTopoSort(adj,q,indegree,topo);
    for(auto &it:topo){
        cout<<it<<" ";
    }
    cout<<endl;
}