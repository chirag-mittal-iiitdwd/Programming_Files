#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        vector<int>indegree(n,0);
        for(auto&it:edges){
            indegree[it[0]]++;
            indegree[it[1]]++;
        }

        for(int i=n-1;i>=0;i--){
            if(indegree[edges[0][1]]>1 && indegree[edges[0][1]]>1){
                return edges[i];
            }
        }

        return {0};
    }
};