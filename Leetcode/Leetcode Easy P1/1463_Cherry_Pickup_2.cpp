#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
    int dp[72][72][72];
    int helper(int r,int c1,int c2,vector<vector<int>>&grid,int m,int n){
        if(r==n){
            return 0;
        }
        if(dp[r][c1][c2]!=-1){
            return dp[r][c1][c2];
        }

        int ans=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nc1=c1+i;
                int nc2=c2+j;
                if(nc1>=0 && nc2>=0 && nc1<m && nc2<m){
                    ans=max(ans,helper(r+1,nc1,nc2,grid,m,n));
                }
            }
        }

        int cherries=0;
        if(c1==c2){
            cherries=grid[r][c1];
        }
        else{
            cherries=grid[r][c1]+grid[r][c2];
        }
        dp[r][c1][c2]=ans+cherries;
        return dp[r][c1][c2];
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();
        return helper(0,0,m-1,grid,m,n);
    }
};

class Solution {
public:
    int dp[70][70][70] = {};
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        return dfs(grid, m, n, 0, 0, n - 1);
    }
    int dfs(vector<vector<int>>& grid, int m, int n, int r, int c1, int c2) {
        if (r == m) return 0; // Reach to bottom row
        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];
        int ans = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nc1 = c1 + i, nc2 = c2 + j;
                if (nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {
                    ans = max(ans, dfs(grid, m, n, r + 1, nc1, nc2));
                }
            }
        }
        int cherries = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        return dp[r][c1][c2] = ans + cherries;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}