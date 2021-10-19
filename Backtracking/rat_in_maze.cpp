#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>>mat,int startx,int starty,int sizeMat){
    if(startx<sizeMat && starty<sizeMat && mat[startx][starty]==1){
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
    int n;
    cin>>n;
    vector<vector<int>>mat(n,vector<int>(n));
    vector<vector<int>>solArr(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    if(RatInMaze(mat,0,0,n,solArr)){
        cout<<"The rat can cross the maze"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<solArr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    else{
        cout<<"Rat is stuck in the maze"<<endl;
    }
    cout<<"Hello World\n"<<endl;
}

// 5
// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1