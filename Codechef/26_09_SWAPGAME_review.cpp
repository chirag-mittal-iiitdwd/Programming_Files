/*
    arr[i]-arr[i+1]   ---> This means when any element is moved to left the vale is subtracted
    and when element is moved from left to right the score is added
    

    https://www.youtube.com/watch?v=5YgqZq8wyXE

    moving elements from one array to make another array
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
        ll a[n],b[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
        }
        ll ans=0;
        for(ll i=1;i<=n;i++){
            ans+=b[i-1]*i;
            ans-=a[i-1]*i;
        }
        cout<<ans<<endl;
    }
    return 0;
}