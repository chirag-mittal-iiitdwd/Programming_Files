#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool hasCycle(vector<vector<int>>&adj,int n){
        vector<int>indegree(n+1,0);

        for(int i=1;i<=n;i++){
            for(auto&it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int cnt=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            cnt++;
            for(auto&it:adj[top]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        return cnt==n;
    }
};