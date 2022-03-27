#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<vector<int>>&graph){
        int n=graph.size();
        int all=(1<<n)-1;
        queue<pair<int,pair<int,int>>>q;  // {node,{distance,currMask}}
        set<pair<int,int>>vis;

        for(int i=0;i<n;i++){
            int mask=(1<<i);
            q.push({i,{0,mask}});
            vis.insert({i,mask});
        }

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int nodeVal=node.first,dist=node.second.first,mask=node.second.second;

            for(auto&temp:graph[nodeVal]){
                int newMask=(mask|(1<<temp));
                if(newMask==all){
                    return dist+1;
                }
                else if(vis.count({temp,newMask})){
                    continue;
                }
                vis.insert({temp,newMask});
                q.push({temp,{dist+1,newMask}});
            }
        }
        return 0;
    }

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size()==1){
            return 0;
        }

        return solve(graph);
    }
};