#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool helper(int i,vector<vector<int>>&adj,vector<int>&color){
        if(color[i]==-1){
            color[i]=1;
        }
        for(auto &it:adj[i]){
            if(color[it]==-1){
                color[it]=1-color[i];
                if(!helper(it,adj,color)){
                    return false;
                }
            }
            else if(color[it]==color[i]){
                return false;
            }
        }
        return true;
    }
    public:
    bool isBipartite(vector<vector<int>>&adj,int n){
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!helper(i,adj,color)){
                    return false;
                }
            }
        }
        return true;
    }
};
