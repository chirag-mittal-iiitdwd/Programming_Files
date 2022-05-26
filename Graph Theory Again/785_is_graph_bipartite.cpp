#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool helper(vector<vector<int>>&adj,vector<int>&color,int i){
        queue<int>q;
        q.push(i);
        color[i]=1;

        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto&it:adj[top]){
                if(color[it]==-1){
                    color[it]=1-color[top];
                    q.push(it);
                }
                else if(color[it]!=1-color[top]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!helper(graph,color,i)){
                    return false;
                }
            }
        }

        return true;
    }
};