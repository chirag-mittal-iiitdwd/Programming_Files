#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    bool left=false;
                    if((i-1)>=0){
                        if(grid[i-1][j]==1){
                            left=false;
                        }
                        else{
                            left=true;
                        }
                    }
                    else{
                        left=true;
                    }

                    bool right=false;
                    if((i+1)<row){
                        if(grid[i+1][j]==1){
                            right=false;
                        }
                        else{
                            right=true;
                        }
                    }
                    else{
                        right=true;
                    }

                    bool up=false;
                    if((j-1)>=0){
                        if(grid[i][j-1]==1){
                            up=false;
                        }
                        else{
                            up=true;
                        }
                    }
                    else{
                        up=true;
                    }

                    bool down=false;
                    if((j+1)<col){
                        if(grid[i][j+1]==1){
                            down=false;
                        }
                        else{
                            down=true;
                        }
                    }
                    else{
                        down=true;
                    }

                    int cnt=0;
                    if(left){
                        cnt++;
                    }
                    if(up){
                        cnt++;
                    }
                    if(right){
                        cnt++;
                    }
                    if(down){
                        cnt++;
                    }

                    ans+=cnt;
                }
            }
        }
        return ans;
    }
};