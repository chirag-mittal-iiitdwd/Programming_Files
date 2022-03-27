#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int cost=0;
        int n=costs.size();
        priority_queue<int,vector<int>,greater<int>>q;

        for(auto&it:costs){
            cost+=it[0];
            q.push(it[1]-it[0]);
        }

        for(int i=0;i<n/2;i++){
            cost+=q.top();
            q.pop();
        }
        return cost;
    }
};

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](const vector<int>&a,vector<int>&b){
            return (a[0]-a[1])<(b[0]-b[1]);
        });
        int cost=0,n=costs.size();
        for(int i=0;i<n;i++){
            if(i<n/2){
                cost+=costs[i][0];
            }
            else{
                cost+=costs[i][1];
            }
        }
        return cost;
    }
};