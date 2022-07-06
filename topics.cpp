#include<bits/stdc++.h>
using namespace std;

class Solution {
    int bfs(vector<bool>&visited,vector<vector<int>>&adj,vector<int>&block){
        int ans=0;
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            bool flag=false;
            for(auto&it:adj[top]){
                if(!visited[it]){
                    if(block[0]==top && block[1]==it){
                        continue;
                    }
                    else{
                        flag=true;
                        visited[it]=true;
                        q.push(it);
                    }
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
  public:
    vector<int> solve(int n, int q, vector<vector<int> > &edge,vector<vector<int> > &query) {
        vector<vector<int>>adj(n);
        for(auto&it:edge){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>ans;
        for(int i=0;i<q;i++){
            vector<bool>visited(n,false);
            int temp=bfs(visited,adj,query[i]);
            ans.push_back(temp);
        }

        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int j=1,num1=4;
    while(++j<=10){
        num1++;
    }
    cout<<num1<<endl;
}

// 10 50 60 90 93 95 99 100 125 130 135 150 180 200 250