#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long int a,b;
        cin>>a>>b;
        if(b&(b-1)){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }
    }
}