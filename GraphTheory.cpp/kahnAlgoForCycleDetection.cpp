/*
    Here we will be using the reverse logic of kahn's algorrithm because
    it worls only for directed acyclic graph and if are not able to generate
    topological sort than that means we have a cycle else not
*/

#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    bool isCyclic(int n,vector<int>adj[]){
        queue<int> q;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[i]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }

        }
        if(cnt==n){
            return false;
        }
        else{
            return true;
        }
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
    bool ans=x.isCyclic(n,adj);
    if(ans){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }

    return 0;
}