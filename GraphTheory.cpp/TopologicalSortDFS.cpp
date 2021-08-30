/*
    In topological sort, the order in which the links are present in the
    graph must be followed in the answer also
    meaning like if there is a link like
                    1 ---------> 2, The link is towards 2
    So in the answer 1 must come before 2.
    There can be multiple topological sort for a given graph
    It should be a directed graph and acyclic graph

    Firstly run a for loop as usual from 0 to number of nodes in the graph
    We would also require a stack
    and also a visited array

    Start iterating over N and then mark the current element as visited
    And if there are no adjacent node for any node than we push that into stack

    if they have some nodes than call recursively if we find any visited node as adjacent
    than we move to next adjacent node and push and leave

    This way we are traversing in such a way that the tail of the arrow get inserted at the last
    so when we pop the the element than it comes first and that is what we wanted
*/

#include<bits/stdc++.h>
using namespace std;
class solution{
    void findTopoSort(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                findTopoSort(it,vis,st,adj);
            }
        }
        st.push(node);
    }
    public:
    vector<int> topoSort(int N,vector<int>adj[]){
        stack<int>st;
        vector<int>vis(N,0);
        // Here the nodes are zzero based so use i=0 we can change it according to problem
        for(int i=0;i<N;i++){
            if(!vis[i]){
                findTopoSort(i,vis,st,adj);
            }
        }
        vector<int>topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    solution x;
    vector<int>sol=x.topoSort(n,adj);
    for(auto it:sol){
        cout<<it<<" ";
    }
    cout<<endl;
}