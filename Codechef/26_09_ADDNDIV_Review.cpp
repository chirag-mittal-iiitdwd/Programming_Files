#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll> primeFactorisation(ll n){
    vector<ll> pFact;
    while(n%2==0){
        pFact.push_back(2);
        n=n/2;
    }
    for(ll i=3;i*i<=n;i+=2){
        while(n%i==0){
            pFact.push_back(i);
            n=n/i;
        }
    }
    if(n>2){
        pFact.push_back(n);
    }
    return pFact;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        vector<ll> primeFact=primeFactorisation(a);
        bool ans="YES";
        for(auto it:primeFact){
            if((b%it)!=0){
                ans="NO";
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}