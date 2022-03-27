#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool helper(vector<vector<int>>&adj,int i,vector<int>&color){
        for(auto&it:adj[i]){
            if(color[it]==-1){
                color[it]=1-color[i];
                if(!helper(adj,it,color)){
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
    bool isBipartide(vector<vector<int>>&adj,int n){
        vector<int>color(n+1,-1);
        
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                color[i]=1;
                if(!helper(adj,i,color)){
                    return false;
                }
            }
        }
        return true;
    }
};