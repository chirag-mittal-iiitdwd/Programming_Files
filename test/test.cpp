#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

bool solve(vector<vector<int>>&mat,int n,int m){
    if(mat[0][0]!=mat[n-1][m-1]){
        return false;
    }

    // if(n<=m){
        for(int i=1;i<n || i<m;i++){
            int x=i,y=0;
            while(x>=0 && y<m){
                // (x,y) (x-1,y) (x,y-1)
                if(x-1>=0 && mat[x][y]>=mat[x-1][y]){
                    return false;
                }
                if(y-1>=0 && mat[x][y]>=mat[x][y-1]){
                    return false;
                }
                x--;
                y++;
            }
        }

        for(int i=1;i<m || i<n;i++){
            int x=n-i,y=i;
            while(x>=0 && y<m){
                if(x-1>=0 && mat[x][y]>=mat[x-1][y]){
                    return false;
                }
                if(y-1>=0 && mat[x][y]>=mat[x][y-1]){
                    return false;
                }
                x--;
                y++;
            }
        }
        return true;
    // }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>mat(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        }

        if(solve(mat,n,m)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}