#include<bits/stdc++.h>
using namespace std;
/*
    For more analysis : 
    https://medium.com/enjoy-algorithm/find-the-row-with-the-maximum-number-of-1s-3193b568c78
    Time Complexity : O( R + C )
*/
int roqWithMaximum1(vector<vector<int>>mat,int r,int c){
    int max1=0;
    int max_row_index=0;
    int curr_col=c-1;
    for(int i=0;i<r;i++){
        while(curr_col>=0 && mat[i][curr_col]==1){
            curr_col--;
            max_row_index=i;
        }
    }
    return max_row_index;
}

int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>>mat(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    cout<<roqWithMaximum1(mat,r,c)<<endl;
}