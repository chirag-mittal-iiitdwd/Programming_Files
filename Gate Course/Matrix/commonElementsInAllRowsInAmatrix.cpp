#include<bits/stdc++.h>
using namespace std;

// vector<int> commonElementsInRows(vector<vector<int>>mat,int r,int c){
//     unordered_map<int,int>m[r];
//     for(int i=0;i<r;i++){
//         for(int j=0;j<c;j++){
//             m[i][mat[i][j]]++;
//         }
//     }
//     vector<int>ans;
//     for(int i=0;i<r;i++){
//         for(auto it:m[i]){
//             +
//         }
//     }
//     return ans;
// }

int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>>mat(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    vector<int>ans=commonElementsInRows(mat,r,c);
    if(ans.size()==0){
        cout<<"No element common in every row"<<endl;
    }
    else{
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}