#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int>q;
        q.push(0);
        vector<bool>vis(n,false);
        vis[0]=true;
        int cnt=0;

        while(!q.empty()){
            int top=q.front();
            q.pop();
            cnt++;

            for(auto&it:rooms[top]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=true;
                }
            }
        }

        return cnt==n;
    }
};