#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        ios_base::sync_with_stdio(false);
        int n=s.size(),i=0,cnt=0,ans=0;

        while(i<n){
            string word="";
            while(i<n && s[i]!='|'){
                word+=s[i];
            }
            if(!(cnt&1)){
                for(auto&it:word){
                    if(it=='*'){
                        ans++;
                    }
                }
            }
            i++;
            cnt++;
        }

        return ans;
    }
};

class Solution {
    int bfs(vector<bool>&visited,int i,vector<vector<int>>&adj){
        queue<int>q;
        q.push(i);
        visited[i]=true;
        int nodes=1;

        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(auto&it:adj[cur]){
                if(!visited[it]){
                    nodes++;
                    visited[it]=true;
                    q.push(it);
                }
            }
        }

        return nodes;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto&it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool>visited(n,false);
        vector<int>indCompSize;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                indCompSize.push_back(bfs(visited,i,adj));
            }
        }

        int ans=0,presum=0,n=indCompSize.size();
        for(int i=0;i<n;i++){
            ans+=indCompSize[i]*presum;
            presum+=indCompSize[i];
        }

        return ans;
    }
};

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int>bucket(32,0);
        int n=nums.size();

        for(int i=0;i<32;i++){
            for(auto&it:nums){
                if(it&(1<<i)){
                    bucket[i]=1;
                    break;
                }
            }
        }

        int ans=0;
        for(int i=0;i<32;i++){
            cout<<bucket[i]<<" ";
            if(bucket[i]==1){
                ans+=(1<<i);
            }
        }
        cout<<endl;
        return ans;      
    }
};