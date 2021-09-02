#include<bits/stdc++.h>
#define ll long long int
using namespace std;

set<ll> duplicateElements(ll arr[],ll n){
    unordered_map<ll,ll>m;
    for(ll i=0;i<n;i++){
        m[arr[i]]++;
    }
    set<ll>ans;
    for(auto it:m){
        if(it.second>1){
            ans.insert(it.first);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,k,l;
        cin>>n>>k>>l;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll maxi=INT_MIN;
        for(ll i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        if(k<=0 && maxi==arr[n-1]){
            string ans="Yes";
            set<ll>x=duplicateElements(arr,n);
            for(auto it:x){
                if(arr[n-1]==it){
                    ans="No";
                    break;
                }
            }
            cout<<ans<<"\n";
        }
        else{
            ll count=0;
            while(maxi>=arr[n-1] && count<l-1){
                arr[n-1]+=k;
                count++;
            }
            if(arr[n-1]>maxi){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    }
    return 0;
}