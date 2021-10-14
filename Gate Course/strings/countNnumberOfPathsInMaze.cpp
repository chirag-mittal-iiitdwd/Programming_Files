/*
    https://www.youtube.com/watch?v=9rt-hFcXd0M
    1D - 10:00
    2D - Just After That
*/

#include<bits/stdc++.h>
using namespace std;

// Number of ways in which we can go from start to end in a N X N matrix
int countPathInMaze2D(int n,int i,int j){
    if(i=n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    return countPathInMaze2D(n,i+1,j)+countPathInMaze2D(n,i,j+1);
}

// Number of ways from start to end in N size row
int countPathInMaze1D(int s,int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count=0;
    // running 7times because we are going with dice input
    for(int i=1;i<7;i++){
        count+=countPathInMaze1D(s+i,e);
    }
    return count;
}

int main(){
    
}