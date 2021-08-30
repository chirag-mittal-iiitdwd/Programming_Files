/*
            1---2--| 
            |   |  4
            5---3--|
        1 is the adjacentcy list of 2
        2 is an adjacent node of 1
        1 is an adjacent node of 2
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    // if it is a weighted graph than we just add a pair instead of int
    // and take the input of weight
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        // If the graph is directed graph one of these two lines will be deleted
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}