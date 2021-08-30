/*
    Components of a graph
    1.  Nodes - These are the stages or vertex. 
        For instance, users in case of facebook
    2.  Edges - Links between states in a graph.
        For instance, connections between users.
          \
          \--> Undirected - Two way edges
          \--> Directed - One way edges
    
    Representaion of graphs ---> Adjacency matrix
                            ---> Adjacency List
    
    1. Adjacency matrix : 2D array where a[i][j] = 1 if there is an
       edge from i to j else a[i][j] = 0
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;

    //declare the adjacent matrix
    int adj[n+1][n+1];

    // take edges as input
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[u][v]=1;
    }
    return 0;

    /*
        Disadvantages of adjacentcy matrix
        1.  Can be used for smaller values of n, you cannot create a
            n*n matrix for n equal to 10^5, in this case we use adjacentcy
            list
    */
}