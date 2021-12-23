#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool inArr(vector<int>arr,int ele){
        for(int i=0;i<arr.size();i++){
            if(arr[i]==ele){
                return true;
            }
        }
        return false;
    }
    void helper(vector<vector<int>>&adj,vector<int>&visited,int i,stack<int>&st){
        visited[i]=1;
        for(auto &it:adj[i]){
            if(!visited[it]){
                helper(adj,visited,it,st);
            }
        }
        st.push(i);
    }
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int course=prerequisites[i][0];
            int req=prerequisites[i][1];
            
            if(!inArr(adj[course],req)){
                adj[req].push_back(course);
            }
            else{
                return {};
            }
        }
        vector<int>visited(numCourses,0);
        stack<int>st;

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                helper(adj,visited,i,st);
            }
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};