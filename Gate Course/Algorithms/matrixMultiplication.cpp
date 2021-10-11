#include<bits\stdc++.h>
using namespace std;

vector<vector<int>> matrixMultiplication(vector<vector<int>>mat1,vector<vector<int>>mat2,int n1,int n2,int n3){
    vector<vector<int>>ansMat(n1,vector<int>(n3));
    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            for(int k=0;k<n2;k++){
                ansMat[i][j]+=(mat1[i][k]*mat2[k][j]);
            }
        }
    }
    return ansMat;
}

int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    vector<vector<int>>mat1(n1,vector<int>(n2));
    vector<vector<int>>mat2(n2,vector<int>(n3));
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            cin>>mat1[i][j];
        }
    }

    for(int i=0;i<n2;i++){
        for(int j=0;j<n3;j++){
            cin>>mat2[i][j];
        }
    }
    vector<vector<int>>ansMat(n1,vector<int>(n3));
    ansMat=matrixMultiplication(mat1,mat2,n1,n2,n3);
    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            cout<<ansMat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}