/*
    Shortest Path In Undirrected Graphs
    declare a minimum priority queue (distance,node) such that node
    with minimum distance stays at the top
    define a distance array make as INT_MAX
    mark distance[src]=0 and insert it into the priority queue
    pick up first node in the queue and look at the adjacency list (node,weight)
    now calculate the distance for each node and keep updating it if it is better
    and if that is better push it into the queue

    repeat all the steps until queue is empty
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,src;
    cin>>n>>m;
    vector<pair<int,int>> g[n+1];

    int a,b,wt;
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        g[a].push_back({b,wt});
        g[b].push_back({a,wt});
    }

    cin>>src;

    // priority_queue(distance,from where it came)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int> distTo(n+1,INT_MAX);

    distTo[src]=0;
    pq.push({0,src});  // (distance,from)
    while(!pq.empty()){
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        for(auto it:g[prev]){
            int next=it.first;
            int nextDist=it.second;
            if((distTo[next]>distTo[prev]+nextDist)){
                distTo[next]=distTo[prev]+nextDist;
                pq.push({distTo[next],next});
            }
        }
    }
    for(auto it:distTo){
        cout<<it<<" ";
    }
    cout<<"\n";
}