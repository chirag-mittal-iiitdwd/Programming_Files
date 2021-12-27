#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool topoSort(vector<vector<int>>&adj,int n){
        vector<int>indegree(n,0);
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

        int cnt=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            cnt++;
            for(auto &it:adj[top]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(cnt==n){
            return false;
        }
        return true;
    }
};