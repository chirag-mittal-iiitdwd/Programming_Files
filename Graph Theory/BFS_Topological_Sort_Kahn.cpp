// Store Indegree of every node in a vector
// Push those nodes which have indegree as 0 into queue
// Keep poping the node from queue and decrease the indegree of the adgacent nodes and if any is zero than push it into queue

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int>topoSort(vector<vector<int>>&adj,int n){
        vector<int>indegree(n,0);
        vector<int>topo;
        for(auto &it:adj){
            for(auto &i:it){
                indegree[i]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int top=q.front();
            topo.push_back(top);
            q.pop();
            for(auto &it:adj[top]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        return topo;
    }
};