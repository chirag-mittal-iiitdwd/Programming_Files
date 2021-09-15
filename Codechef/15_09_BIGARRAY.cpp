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
        ll n,s;
        cin>>n>>s;
        ll x=(n*(n+1))/2;
        ll toFind=x-s;
        if(toFind<=0 || toFind>=(n+1)){
            cout<<-1<<endl;
        }
        else{
            cout<<toFind<<endl;
        }
    }
    return 0;
}