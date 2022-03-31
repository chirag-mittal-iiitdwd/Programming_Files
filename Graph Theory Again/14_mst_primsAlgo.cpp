#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void primsAlgorithm(vector<vector<pair<int,int>>>&adj,int n){
        vector<int>parent(n,-1);
        vector<int>key(n,INT_MAX);
        vector<bool>mstSet(n,false);

        key[0]=0;
        parent[0]=-1;

        for(int count=0;count<n-1;count++){
            int mini=INT_MAX,u;

            for(int v=0;v<n;v++){
                if(mstSet[v]==false && key[v]<mini){
                    mini=key[v],u=v;
                }
            }

            mstSet[u]=true;

            for(auto&it:adj[u]){
                int v=it.first;
                int weight=it.second;
                if(mstSet[v]==false && weight<key[v]){
                    parent[v]=u,key[v]=weight;
                }
            }
        }

        for(int i=1;i<n;i++){
            cout<<parent[i]<<" - "<<i<<endl;
        }
    }
};

class Solution{
    public:
    void primsAlgorithm(vector<vector<pair<int,int>>>&adj,int n){
        vector<int>parent(n,-1);
        vector<int>key(n,INT_MAX);
        vector<bool>mstSet(n,false);

        key[0]=0;
        parent[0]=-1;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});

        for(int count=0;count<n-1;count++){
            int u=q.top().second;
            q.pop();

            mstSet[u]=true;

            for(auto&it:adj[u]){
                int v=it.first;
                int weight=it.second;
                if(mstSet[v]==false && weight<key[v]){
                    parent[v]=u;
                    q.push({key[v],v});
                    key[v]=weight;
                }
            }
        }

        for(int i=1;i<n;i++){
            cout<<parent[i]<<" - "<<i<<endl;
        }
    }
};