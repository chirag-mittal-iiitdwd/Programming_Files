#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();

        auto inside=[&](int row,int col){
            return row>=0 && row<n && col>=0 && col<m;
        };

        vector<pair<int,int>>dirs{{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<bool>>vis(n,vector<bool>(m));
        int answer=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    answer++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    vis[i][j]=true;
                    while(!q.empty()){
                        auto p=q.front();
                        q.pop();

                        for(auto&dir:dirs){
                            int new_row=p.first+dir.first;
                            int new_col=p.second+dir.second;
                            if(inside(new_row,new_col) && !vis[new_row][new_col] && grid[new_row][new_col]=='1'){
                                q.push({new_row,new_col});
                                vis[new_row][new_col]=true;
                            }
                        }
                    }
                }
            }
        }

        return answer;
    }
};