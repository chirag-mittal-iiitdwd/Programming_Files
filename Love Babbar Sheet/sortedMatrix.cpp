#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> sortedMatrix(int n,vector<vector<int>>mat){
    vector<int>allElements;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            allElements.push_back(mat[i][j]);
        }
    }
    sort(allElements.begin(),allElements.end());
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=allElements[cnt];
            cnt++;
        }
    }
    // for(int i=0;i<n*n;i++){
    //     cout<<allElements[i]<<" ";
    // }
    // cout<<endl;
    return mat;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>mat(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    vector<vector<int>> sortedMat=sortedMatrix(n,mat);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}