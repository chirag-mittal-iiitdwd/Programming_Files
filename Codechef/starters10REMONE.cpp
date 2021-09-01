#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a;
        vector<ll>b;
        unordered_set<ll>s;
        ll x;
        for(ll i=0;i<n;i++){
            cin>>x;
            a.push_back(x);
            s.insert(x);
        }
        for(ll i=0;i<n-1;i++){
            cin>>x;
            b.push_back(x);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll ans=b[0]-a[1];
        for(auto it:b){
            if(s.count(it-ans)==0){
                ans=b[0]-a[0];
                break;
            }
        }
        if(ans<=0){
            ans=b[0]-a[0];
        }
        cout<<ans<<endl;
    }
    return 0;
}