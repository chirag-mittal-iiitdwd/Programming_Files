#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n);
        for(auto&it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        priority_queue<int>q;
        for(int i=0;i<n;i++){
            q.push(adj[i].size());
        }

        int first=q.top();
        q.pop();

        // if(first==0 && second==0){
        //     return 0;
        // }
        // else if(first==0){
        //     return second;
        // }
        // else if(second==0){
        //     return first;
        // }

        int ans=INT_MIN;

        while(!q.empty()){
            int second=q.top();
            q.pop();
            vector<bool>visited(n,false);
            queue<int>pq;
            pq.push(second);

            while(!pq.empty()){
                int top=pq.front();
                pq.pop();
                for(auto&it:adj[top]){
                    if(!visited[it]){
                        pq.push(it);
                        visited[it]=true;
                    }
                }
            }
            if(visited[first] && visited[second]){
                ans=max(ans,first+second-1);
            }
            else{
                ans=max(ans,first+second);
            }
        }

        return ans;
    }
};


//      0  --  1
//             |
//             2  -- 3 
//             |
//             4

//             5 -- 6
//             |
//             7