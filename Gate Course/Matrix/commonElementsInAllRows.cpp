#include<bits/stdc++.h>
using namespace std;

void printCommonElements(vector<vector<int>>mat,int r,int c){
    unordered_map<int,int>mp;
    for(int i=0;i<c;i++){
        mp[mat[0][i]]=1;
    }
    for(int i=1;i<r;i++){
        for(int j=0;j<c;j++){
            if(mp[mat[i][j]]==i){
                mp[mat[i][j]]++;
                if(i==r-1 && mp[mat[i][j]]==r){
                    cout<<mat[i][j]<<" ";
                }
            }
        }
    }
    cout<<endl;
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
    printCommonElements(mat,r,c);
}