/*
    The basic rule is first visit the adjacent nodes and then 
    carry on with other nodes

    Now there can be multiple components of a tree so, inorder
    to ensure safety we use a for loop to traverse through each node
    and make a visited array

    for bfs funcion we make a queue and insert first element and
    continue to traverse until the queue dosn't become empty
    and look up to adjacentcy list and push and mark visited
*/

#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> &visited,int i,vector<int>&bfsArr,vector<vector<int>>&a){
    queue<int> q;
    q.push(i);
    visited[i]=1;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        bfsArr.push_back(top);
        for(int i=0;i<a[top].size();i++){
            if(visited[a[top][i]]!=1){
                visited[a[top][i]]=1;
                q.push(a[top][i]);
            }
        }
    }
}

int main(){
    int n,m;
    cout<<"Enter number of nodes : ";
    cin>>n;
    cout<<"Enter number of edges : ";
    cin>>m;
    vector<vector<int>> a(n+1);
    for(int i=0;i<m;i++){
        cout<<"Enter node neighbours : ";
        int u,v;
        cin>>u>>v;
        a[v].push_back(u);
        a[u].push_back(v);
    }
    vector<int> visited(n+1,0);
    vector<int> bfsArr;

    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            bfs(visited,i,bfsArr,a);
        }
    }
    cout<<"The required BFS traversal is : ";
    for(auto it:bfsArr){
        cout<<it<<" ";
    }
    cout<<endl;
}