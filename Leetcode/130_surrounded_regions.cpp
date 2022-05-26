#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();

        auto inside=[&](int x,int y){
            return x>=0 && x<n && y>=0 && y<m;
        };

        vector<pair<int,int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>>vis(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    vis[i][j]=1;
                    while(!q.empty()){
                        auto p=q.front();
                        q.pop();
                        for(auto&dir:dirs){
                            int new_x=p.first+dir.first;
                            int new_y=p.first+dir.first;
                            if(inside(new_x,new_y) && !vis[new_x][new_y] && board[new_x][new_y]=='O'){
                                vis[new_x][new_y]=1;
                                q.push({new_x,new_y});
                            }
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1){
                    board[i][j]='X';
                }
            }
        }
    }
};