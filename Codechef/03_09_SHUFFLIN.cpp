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
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<ll>odd;
        vector<ll>even;
        for(ll i=0;i<n;i++){
            if(arr[i]%2==0){
                even.push_back(arr[i]);
            }
            else{
                odd.push_back(arr[i]);
            }
        }

        ll counter=0;
        while(counter<n && even.size()!=0 && odd.size()!=0){
            if(counter%2!=0){
                arr[counter]=odd.back();
                odd.pop_back();
            }
            else{
                arr[counter]=even.back();
                even.pop_back();
            }
            counter++;
        }

        while(even.size()!=0){
            arr[counter]=even.back();
            even.pop_back();
            counter++;
        }

        while(odd.size()!=0){
            arr[counter]=odd.back();
            odd.pop_back();
            counter++;
        }
        ll ans=0;
        for(ll i=1;i<=n;i++){
            ans+=((arr[i-1]+i)%2);
        }
        cout<<ans<<endl;
    }
    return 0;
}