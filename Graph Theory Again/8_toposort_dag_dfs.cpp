#include<bits/stdc++.h>
using namespace std;

class Solution{
    void helper(vector<vector<int>>&adj,vector<bool>&visited,int i,stack<int>&st){
        visited[i]=true;
        for(auto&it:adj[i]){
            if(!visited[it]){
                helper(adj,visited,i,st);
            }
        }
        st.push(i);
    }
    public:
    vector<int>topoSort(vector<vector<int>>&adj,int n){
        stack<int>st;
        vector<bool>visited(n+1,false);

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                helper(adj,visited,i,st);
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