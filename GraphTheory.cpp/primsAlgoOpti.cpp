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
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    for(int count=0;count<n-1;count++){
        int mini=INT_MAX,u;

        // Finding the index with minimum possible key value
        int u=pq.top().second;
        pq.pop();
        mstSet[u]=true;

        for(auto it:adj[u]){
            int v=it.first;
            int weight=it.second;

            // if is it not a part of MST and also the current weight
            // is grater than previous key than put that weight into key[index]
            // Also marking the parent with previous node
            if(mstSet[v]==false && weight<key[v]){
                parent[v]=u;
                pq.push({key[v],v});
                key[v]=weight;
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<parent[i]<<" - "<<i<<"\n";
    }
    return 0;
}

// time completity : N logN