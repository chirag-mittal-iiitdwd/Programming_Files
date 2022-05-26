#include<bits/stdc++.h>
using namespace std;

class Solution {
    double dfs(string a,string b,unordered_map<string,unordered_map<string,double>>graph,unordered_set<string>&visited){
        if(graph[a].find(b)!=graph[a].end()){
            return graph[a][b];
        }

        for(auto&node:graph[a]){
            if(visited.find(node.first)==visited.end()){
                visited.insert(node.first);
                double val=dfs(node.first,b,graph,visited);
                if(val){
                    graph[a][b]=node.second*val;
                    return graph[a][b];
                }
            }
        }
        
        return 0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>>mp;
        int n=equations.size();

        for(int i=0;i<n;i++){
            mp[equations[i][0]][equations[i][1]]=values[i];
            mp[equations[i][1]][equations[1][0]]=(double)1/values[i];
        }

        vector<double>ans;
        for(int i=0;i<queries.size();i++){
            unordered_set<string>visited;
            double val=dfs(queries[i][0],queries[i][1],mp,visited);
            if(!val){
                ans.push_back(-1.0);
            }
            else{
                ans.push_back(val);
            }
        }

        return ans;
    }
};