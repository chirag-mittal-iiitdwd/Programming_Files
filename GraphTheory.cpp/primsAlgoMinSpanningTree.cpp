/*
    When you can convert a graph into a tree with exaclty N nodes
    and n-1 edges, every node must be reachable with every other node

    Take any one node and find the least weighted edge among adjacents edges
    Now than check the adjacents edges of of the both connected nodes
    After finding the minimum one than connect it
    Again check of these three nodes and keep repeating until all nodes are visited

    One more thing there must not be any cycle formed

    ----> Implimentaion
    Three arrays : 
        1. the key array : initialised with infinity and 0th index as 0
        2. the mst array : initialised with false
        3. the parent array : initialised with -1
    
    Now in starting mark mst of 0 = true and look for adjacent nodes
    than take the weights of adjacents weights and and mark them 
    according to the node's index in key array,
    now iterate over key array anf find the least weight mark mst for that
    node as true and also put the previous node into parent of that node

    repeat until all mst becomes true than go to parent array and iterate from
    1 to 4
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a,b,wt;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }
    int parent[n];
    int key[n];
    bool mstSet[n];
    for(int i=0;i<n;i++){
        key[i]=INT_MAX,mstSet[i]=false,parent[i]=-1;
    }
    key[0]=0;
    for(int count=0;count<n-1;count++){
        int mini=INT_MAX,u;

        // Finding the index with minimum possible key value
        for(int v=0;v<n;v++){
            if(mstSet[v]==false && key[v]<mini){
                mini=key[v],u=v;
            }
        }
        mstSet[u]=true;

        for(auto it:adj[u]){
            int v=it.first;
            int weight=it.second;

            // if is it not a part of MST and also the current weight
            // is grater than previous key than put that weight into key[index]
            // Also marking the parent with previous node
            if(mstSet[v]==false && weight<key[v]){
                parent[v]=u,key[v]=weight;
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<parent[i]<<" - "<<i<<"\n";
    }
    return 0;
}

// Time Complexity : greater than O(n^2)
// Space Complexity : parent,key,mstSet,Adjlist