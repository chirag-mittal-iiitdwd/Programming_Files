/*  
    everything else remains the same just there is a small change and
    that is if adjacent node at any point is already visited than we return true
*/
#include<bits/stdc++.h>
using namespace std;
bool bfs(vector<int> &visited,int i,vector<int>&bfsArr,vector<vector<int>>&a){
    queue<int> q;
    q.push(i);
    visited[i]=1;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        bfsArr.push_back(top);
        for(int i=0;i<a[top].size();i++){
            if(visited[a[top][i]]==1){
                return true;
            }
            else if(visited[a[top][i]]!=1){
                visited[a[top][i]]=1;
                q.push(a[top][i]);
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        a[v].push_back(u);
        a[u].push_back(v);
    }
    vector<int> visited(n+1,0);
    vector<int> bfsArr;
    bool answer;
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            answer=bfs(visited,i,bfsArr,a);
            if(answer){
                break;
            }
        }
    }
    if(answer){
        cout<<"Cycle Detected\n";
    }
    else{
        cout<<"Cycle not detected\n";
    }
}