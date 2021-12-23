#include<bits/stdc++.h>
using namespace std;

class Solution{
    void helper(vector<vector<int>>&adj,int&i,stack<int>&st,vector<int>&visited){
        visited[i]=1;
        for(auto &it:adj[i]){
            if(!visited[i]){
                helper(adj,it,st,visited);
            }
        }
        st.push(i);
    }
    public:
    vector<int>topoSort(vector<vector<int>>&adj,int&n){
        stack<int>st;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                helper(adj,i,st,visited);
            }
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};