#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll maxi=INT_MIN;
        for(ll i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        ll ans=0;
        for(ll i=k-1;i<n;i++){
            if(maxi==arr[i]){
                ans+=n-i;
            }
        }
        cout<<ans<<endl;
    }
}