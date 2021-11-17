#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int>&bfsArr,int i,vector<vector<int>>&adj,vector<int>&visited){

    // Declaring the queue because queue uses FIFO and with the help for FIFO we will not go into Depth
    queue<int>q;
    q.push(i); // Pushing the first node of the component
    visited[i]=1; // Marking that node as visited
    while(!q.empty()){ // Keep running until the queue is not empty
        int top=q.front();
        q.pop(); 
        bfsArr.push_back(top); // Taking out the first element and pushing it into the ans
        for(auto it:adj[top]){ // Pushing all the adjacent nodes of current node into our queue
            if(!visited[it]){ // If that node is not visited already then pushing it onto queue and marking visited
                q.push(it); 
                visited[it]=1;
            }
        }
    }
}

int main(){
    // n : number of nodes
    // m : number of edges
    int n,m;
    cin>>n>>m;

    // The size is n+1 because we want to create graph which has zero based indexing and the indexes start from 1
    vector<vector<int>>adj(n+1);

    // Taking input for a particular edge
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // The visited array and the bfs array
    vector<int>visited(n+1,0);
    vector<int>bfsArr;

    // Running the bfs function for all the components
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            // Passing the bfs array by refrence
            bfs(bfsArr,i,adj,visited);
        }
    }

    // Finally printing the bfs with for-each loop
    for(auto it:bfsArr){
        cout<<it<<" ";
    }
    cout<<endl;
}
// Input :
// 7 6
// 1 2
// 2 3
// 2 7
// 3 5
// 7 5
// 4 6

// Output:
// 1 2 3 7 5 4 6