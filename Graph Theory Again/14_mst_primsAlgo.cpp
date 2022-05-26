#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(N)
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

            // The key array stores the path weight from the current index 
            // to that index and we then compare the things and find the minimum 
            // weight as we want to find the minimum weight
            for(int v=0;v<n;v++){
                if(mstSet[v]==false && key[v]<mini){
                    mini=key[v],u=v;
                }
            }

            // After finding the mini index we mark it as a part of mst
            mstSet[u]=true;

            // Now iterating through the adjacent nodes of the current node
            // which was marked visited
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

// Time Complexity : O(N logN)
class Solution{
    public:
    void primsAlgorithm(vector<vector<pair<int,int>>>&adj,int n){
        vector<int>parent(n,-1);
        vector<int>key(n,INT_MAX);
        vector<bool>mstSet(n,false);

        key[0]=0;
        parent[0]=-1;

        // this will store { key, index} --> because every time we need to find the 
        // minimum key and then mark its index as visited or it as a part of the mst
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