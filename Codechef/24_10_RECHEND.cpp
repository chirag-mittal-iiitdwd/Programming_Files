/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool isSafe(vector<vector<int>>mat,int startx,int starty,int sizeMat){
    if(startx<sizeMat && starty<sizeMat && mat[startx][starty]==0){
        return true;
    }
    return false;
}

bool RatInMaze(vector<vector<int>>mat,int startx,int starty,int sizeMat,vector<vector<int>>&solArr){
    if(startx==sizeMat-1 && starty==sizeMat-1){
        return true;
    }
    if(isSafe(mat,startx,starty,sizeMat)){
        solArr[startx][starty]=1;
        if(RatInMaze(mat,startx+1,starty,sizeMat,solArr)){
            return true;
        }
        if(RatInMaze(mat,startx,starty+1,sizeMat,solArr)){
            return true;
        }
        solArr[startx][starty]=0;
        return false;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>solArr(n,vector<int>(n));
        vector<vector<int>>mat(n,vector<int>(n));
        vector<pair<int,int>>p(n);
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            mat[a][b]=1;
        }
        if(RatInMaze(mat,0,0,n,solArr)){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}