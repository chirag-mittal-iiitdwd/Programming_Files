/*
    Every node will be parent by himself in starting
    There will be a rank array whivh will store the ranks of nodes
    in the array, and initially everything will be zero

    When we attach two similar kind of rank nodes than make sure to increasing the parent by 1
    The lesser rank one becomes the child of higher rank
    When the ranks are different than there is no need to incerase the rank
*/

#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int rankArr[100000];

void makeSet(int n){
    for(int i=0;i<=n;i++){
        parent[i]=i;
        rankArr[i]=i;
    }
}

int findPar(int node){
    // Time complexity = O(4*a) --> constant time
    if(node==parent[node]){
        return node;
    }

    // This step is the path compresion step
    return parent[node]=findPar(parent[node]);
}

void unionOper(int u,int v){
    u=findPar(u);
    v=findPar(v);
    if(rankArr[u]<rankArr[v]){
        parent[u]=v;
    }
    else if(rankArr[v]<rankArr[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rankArr[u]++;
    }
}

int main(){
    int n;
    cin>>n;
    makeSet(n);
    while(n--){
        int u,v;
        cin>>u>>v;
        unionOper(u,v);
    }
    // if u ans v are belonging to same component or not
    int u,v;
    cin>>u>>v;
    // Bascilly finding the main parent
    if(findPar(u)!=findPar(v)){
        cout<<"Different Component\n";
    }
    else{
        cout<<"Same Parent\n";
    }
}