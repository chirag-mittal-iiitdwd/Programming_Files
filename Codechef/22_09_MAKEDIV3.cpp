/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll powerOf10=pow(10,n-1)+4;
        ll rem=(powerOf10)%3;
        ll sm3=powerOf10-rem;
        ll ans=0;
        while(true){
            if(((sm3%9)!=0)&&(sm3%2)){
                ans=sm3;
                break;
            }
            sm3+=3;
        }
        cout<<ans<<endl;
    }
    return 0;
}