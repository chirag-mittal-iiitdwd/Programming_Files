#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0){
            return 0;
        }
        int n=matrix.size(); // rows 
        int m=matrix[0].size(); // cols
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));

        int maxi=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                    maxi=max(maxi,dp[i][j]);
                }
            }
        }
        return maxi*maxi;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>mat(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            mat[i].push_back(ch);
        }
    }
    Solution obj;
    cout<<obj.maximalSquare(mat)<<endl;
}