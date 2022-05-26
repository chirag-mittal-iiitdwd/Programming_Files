#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>&adj,vector<vector<int>>&ans,int n,vector<int>cur,int curNode){
        if(curNode==n-1){
            ans.push_back(cur);
            return;
        }

        for(auto&it:adj[curNode]){
            cur.push_back(it);
            dfs(adj,ans,n,cur,it);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>ans;
        vector<int>cur={0};
        dfs(graph,ans,n,cur,0);
        return ans;
    }
};