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
        string str;
        cin>>str;
        ll arr[n];
        for(ll i=0;i<n;i++){
            arr[i]=(str[i]-'0');
        }
        ll cnt=0;
        for(ll i=1;i<n;i++){
            for(ll j=i+1;j<=n;j++){
                if((j-i)==abs(arr[i-1]-arr[j-1])){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}