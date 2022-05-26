#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);

        for(auto&it:prerequisites){
            indegree[it[0]]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int cnt=0;
        while(!q.empty()){
            cnt++;
            int top=q.front();
            q.pop();
            for(auto&it:prerequisites[top]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(cnt==numCourses){
            return true;
        }
        return false;
    }
};

// [second,first]
// Edge prerequisites[0] <-- prerequisites[1]
// indegree[prerequisites[0]]++;
// topo meaning : u --> v topo : [u,v]
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);

        vector<vector<int>>adj(numCourses);

        for(auto&it:prerequisites){
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int cnt=0;
        while(!q.empty()){
            cnt++;
            int top=q.front();
            q.pop();
            for(auto&it:adj[top]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(cnt==numCourses){
            return true;
        }
        return false;
    }
};