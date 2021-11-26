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
        ll n,m;
        cin>>n>>m;
        ll mark=(n/2)-1;
        ll zero=n-m;
        if(m>mark){
            cout<<zero<<endl;
        }
        else{
            ll grp=m+1;
            ll div=zero/grp;
            if(zero%grp==0){
                ll ans=grp*((div*(div+1))/2);
                cout<<ans<<endl;
            }
            else{
                ll rem=zero%grp;
                ll rem_=grp-rem;
                ll ans1=rem*((div+1)*(div+2))/2;
                ll ans2=rem_*((div)*(div+1))/2;
                cout<<ans1+ans2<<endl;
            }
        }
    }
    return 0;
}