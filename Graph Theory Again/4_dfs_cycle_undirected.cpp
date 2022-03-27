#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool helper(vector<vector<int>>&adj,vector<bool>visited,int i,int par){
        visited[i]=true;

        for(auto&it:adj[i]){
            if(!visited[it]){
                if(helper(adj,visited,it,i)){
                    return true;
                }
            }
            else if(par!=it){
                return true;
            }
        }
        return false;
    }
    public:
    bool isCycle(vector<vector<int>>&adj,int n){
        vector<bool>visited(n+1,false);
        
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                if(helper(adj,visited,i,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};