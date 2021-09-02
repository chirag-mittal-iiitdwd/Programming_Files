/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a[3];
        int b[3];
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        for(int i=0;i<3;i++){
            cin>>a[i];
            m1[a[i]]++;
        }
        for(int i=0;i<3;i++){
            cin>>b[i];
            m2[b[i]]++;
        }
        if(m1[1]==m2[1]){
            cout<<"Pass"<<endl;
        }
        else{
            cout<<"Fail"<<endl;
        }
    }
    return 0;
}