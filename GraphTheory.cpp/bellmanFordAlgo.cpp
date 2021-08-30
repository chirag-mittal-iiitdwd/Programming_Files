/*
    For finding shortest path in negative weighted graph
    Dosn't work for cyclic graph with negative edges because the distance 
    will keep on decreasing whenever we iterate over the graph

    Also can be used to detect if there is a negative cycle
    works for only directed graphs

    1. Take input
    2. dist[src]=0 all other INT_MAX
    3. Relax all the edges N-1 times
        Relaxatation means if(dis[u]+wt<dist[v]){
                                dist[v]=dist[u]+wt;
                           }
    if the dustance reduces after doing one more relaxation after N-1 than it has cycle

    Time Complexity = O(N-1)*O(Edges)
    Space Complexity = O(N)
*/

#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int u;
    int v;
    int wt;
    node(int first,int second,int weight){
        u=first;
        v=second;
        wt=weight;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<node>edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
    int src;
    cin>>src;
    int inf=10000000;
    vector<int>dist(n,inf);
    for(int i=0;i<=n-1;i++){
        for(auto it:edges){
            if(dist[it.u]+it.wt<dist[it.v]){
                dist[it.v]=dist[it.u]+it.wt;
            }
        }
    }

    int fl=0;
    for(auto it:edges){
        if(dist[it.u]+it.wt<dist[it.v]){
            cout<<"Negative Cycle\n";
            fl=1;
            break;
        }
    }

    if(!fl){
        for(int i=0;i<n;i++){
            cout<<i<<" "<<dist[i]<<endl;
        }
    }

    return 0;
}