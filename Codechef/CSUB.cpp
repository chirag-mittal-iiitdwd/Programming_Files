/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string str;
        cin>>str;
        ll cnt=0;
        for(ll i=0;i<n;i++){
            if(str[i]=='1'){
                cnt++;
            }
        }
        ll perm=(cnt*(cnt+1))/2;
        cout<<perm<<endl;
    }
    return 0;
}