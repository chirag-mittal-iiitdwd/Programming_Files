#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,v;
        cin>>n>>v;
        ll maxi=(n*(n-1))/2;
        ll mini=0;
        if(v==1){
            mini=maxi;
        }
        else{
            if(v>=n-1){
                mini=n-1;
            }
            else{
                mini+=v+((n-v)*(n-v+1))/2-1;
            }
        }
        cout<<maxi<<" "<<mini<<endl;
    }
    return 0;
}