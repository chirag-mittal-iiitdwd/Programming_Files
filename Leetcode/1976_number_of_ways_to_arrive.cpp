#include<bits/stdc++.h>
using namespace std;

class Solution {
    long long int mod=1e9+7;
    long long int helper(vector<vector<pair<long long int,long long int>>>&adj,long long int n,long long int src){
        vector<long long int>dist(n,LONG_MAX);
        vector<long long int>ways(n);

        ways[src]=1;
        dist[src]=0;
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<>>minHeap;
        minHeap.push({0,0});
        while(!minHeap.empty()){
            auto [curDist,curSrc]=minHeap.top();
            minHeap.pop();
            if(curDist>dist[curSrc]){
                continue;
            }

            for(auto [nextNode,nextTime]:adj[curSrc]){
                if(dist[nextNode]>curDist+nextTime){
                    dist[nextNode]=curDist+nextTime;
                    ways[nextNode]=ways[curSrc];
                    minHeap.push({dist[nextNode],nextNode});
                }
                else if(dist[nextNode]==curDist+nextTime){
                    ways[nextNode]=(ways[nextNode]+ways[curSrc])%(mod);
                }
            }
        }

        return ways[n-1];
    }
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long int,long long int>>>adj(n);
        for(auto&it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        return (int)helper(adj,(long long int)n,0);
    }
};