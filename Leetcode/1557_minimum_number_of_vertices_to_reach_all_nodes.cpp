#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>indegree(n,false);
        for(auto&it:edges){
            indegree[it[1]]=true;
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==false){
                ans.push_back(i);
            }
        }

        return ans;
    }
};