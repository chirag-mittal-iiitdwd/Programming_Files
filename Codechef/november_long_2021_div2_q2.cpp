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
        ll odd=0;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            if(x%2){
                odd++;
            }
        }
        if(odd%2){
            odd--;
            cout<<odd/2<<endl;
        }
        else{
            cout<<odd/2<<endl;
        }
    }
    return 0;
}