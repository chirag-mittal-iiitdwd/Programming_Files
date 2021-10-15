#include<bits\stdc++.h>
using namespace std;

void rotate(vector<vector<int>>&mat,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=i+1;j<c;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<r;i++){
        int low=0,high=c-1;
        while(low<high){
            swap(mat[i][low],mat[i][high]);
            low++;
            high--;
        }
    }
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
    rotate(mat,r,c);

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}