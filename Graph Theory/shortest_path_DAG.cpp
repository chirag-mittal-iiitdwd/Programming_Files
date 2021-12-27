#include<bits/stdc++.h>
using namespace std;

class Solution{
    void findTopoSort(stack<int>&st,vector<vector<pair<int,int>>>&adj,int i,vector<int>&visited){
        visited[i]=1;
        for(auto &it:adj[i]){
            if(!visited[it.first]){
                findTopoSort(st,adj,it.first,visited);
            }
        }
        st.push(i);
    }
    public:
    vector<int>distance(vector<vector<pair<int,int>>>&adj,int n,int src){
        vector<int>visited(n,0);
        stack<int>st;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                findTopoSort(st,adj,i,visited);
            }
        }

        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(dist[node]!=INT_MAX){
                for(auto &it:adj[node]){
                    if(dist[node]+it.second<dist[it.first]){
                        dist[it.first]=dist[node]+it.second;
                    }
                }
            }
        }

        return dist;
    }
};