#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int rankAr[100000];

void makeSet(int n){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        rankAr[i]=0;
    }
}

int findpar(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findpar(parent[node]);
}

void unionOper(int u,int v){
    u=findpar(u);
    v=findpar(v);

    if(rankAr[u]<rankAr[v]){
        parent[u]=v;
    }
    else if(rankAr[v]<rankAr[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rankAr[u]++;
    }
}

int main(){
    int n;
    cin>>n;
    makeSet(n);
    int m;
    cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        unionOper(u,v);
    }

    // Check for same parent;
    int u,v;
    cin>>u>>v;
    if(findpar(u)!=findpar(v)){
        cout<<"Different\n";
    }
    else{
        cout<<"Same\n";
    }
}