#include<bits/stdc++.h>
using namespace std;

void multiplyMatrix(vector<vector<int>>&mat1,vector<vector<int>>&mat2,int n){
    vector<vector<int>>ans(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int cnt=0;
            for(int k=0;k<n;k++){
                cnt+=mat1[i][k]*mat2[k][j];
            }
            ans[i][j]=cnt;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat1[i][j]=ans[i][j];
        }
    }
}

vector<vector<int>>matrixExp(vector<vector<int>>&mat1,int b,int n){
    vector<vector<int>>ans(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                ans[i][j]=1;
            }
            else{
                ans[i][j]=0;
            }
        }
    }

    while(b){
        if(b&1){
            multiplyMatrix(ans,mat1,n);
            b--;
        }
        else{
            multiplyMatrix(mat1,mat1,n);
            b/=2;
        }
    }

    return ans;
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
    int power;
    cin>>power;

    mat=matrixExp(mat,power,n);
    for(auto &it:mat){
        for(auto &i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}