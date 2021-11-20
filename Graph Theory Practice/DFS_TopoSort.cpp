/*
    Topological sorting for Directed Acyclic Graph (DAG) 
    is a linear ordering of vertices such that for every directed edge u v, 
    vertex u comes before v in the ordering. 

    There can be many topo sort but return one of them
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    void dfsToposort(vector<int>&visited,vector<vector<int>>adj,int i,stack<int>&st){
        visited[i]=1;
        for(auto &it:adj[i]){
            if(!visited[it]){
                dfsToposort(visited,adj,it,st);
            }
        }
        st.push(i);
    }
    void topoSortHelp(vector<vector<int>>adj,int n,stack<int>&st){
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfsToposort(visited,adj,i,st);
            }
        }
    }
    public:
    vector<int>topoSort(vector<vector<int>>adj,int n){
        stack<int>st;
        topoSortHelp(adj,n,st);
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    cout<<"EDGE IS FROM FIRST INPUT TO SECOND"<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    Solution obj;
    vector<int>topoSort=obj.topoSort(adj,n);
    for(auto &it:topoSort){
        cout<<it<<" ";
    }
    cout<<endl;
}