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
        int n,s;
        cin>>n>>s;
        if(n>=s){
            cout<<s<<endl;
        }
        else{
            cout<<abs(s-2*n)<<endl;
        }
    }
    return 0;
}