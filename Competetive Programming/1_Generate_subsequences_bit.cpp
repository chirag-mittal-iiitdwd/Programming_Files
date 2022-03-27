#include<bits/stdc++.h>
using namespace std;

void generateSubstring(vector<vector<int>>&ans,int n){
    for(int i=0;i<(1<<n);i++){
        vector<int>subseq;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                subseq.push_back(j);
            }
        }
        ans.push_back(subseq);
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>v;
    generateSubstring(v,n);

    for(auto&it:v){
        for(auto&i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}