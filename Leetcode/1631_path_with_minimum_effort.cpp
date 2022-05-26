#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();

        // Lamda function for checking if the current index is inside the matrix
        auto inside=[&](int x,int y){
            return x<n && y<m && x>=0 && y>=0;
        };

        // defining the directions, ie the all 4 firections
        vector<pair<int,int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};

        // Defining the matrix that will store maximum effort 
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));

        // structure -> { path_length , { x_cord , y_cord } }, will give the minimum path_length way in every iteration
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;

        // inserting starting index
        q.push({0,{0,0}});
        dp[0][0]=0;

        // BFS starts
        while(!q.empty()){
            // taking the indexs with minimum effort
            int x=q.top().second.first,y=q.top().second.second,effort=q.top().first;
            q.pop();

            // going in all directions
            for(auto&dir:dirs){
                
                // forming new indexes
                int new_x=x+dir.first,new_y=y+dir.second;

                // if thoses new indxes are inside the scope of matrix
                if(inside(new_x,new_y)){

                    // calcutaing current effort
                    int path_length=abs(heights[new_x][new_y]-heights[x][y]);

                    // calcualting max of current effort and the already known effort
                    int new_effort=max(path_length,effort);

                    // if the maximum of effort is smaller that already know of new index, than we update
                    if(new_effort<dp[new_x][new_y]){
                        dp[new_x][new_y]=new_effort;
                        q.push({new_effort,{new_x,new_y}});
                    }
                }
            }
        }

        return dp[n-1][m-1];
    }
};