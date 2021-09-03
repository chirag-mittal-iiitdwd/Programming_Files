#include<bits/stdc++.h>
using namespace std;
string isSubset(int a[],int b[],int n,int m){
    unordered_set<int>a1;
    unordered_set<int>a2;
    for(int i=0;i<n;i++){
        a1.insert(a[i]);
    }
    for(int i=0;i<m;i++){
        a2.insert(b[i]);
    }
    string ans="Yes";
    for(auto it:a2){
        if(a1.count(it)==0){
            ans="No";
            break;
        }
    }
    return ans;
} 
int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b[m];
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    cout<<isSubset(a,b,n,m)<<endl;
}