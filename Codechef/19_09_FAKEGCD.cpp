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
        ll evenCount=2;
        ll oddCount=1;
        for(ll i=0;i<n;i++){
            if((i%2)==0){
                arr[i]=oddCount;
                oddCount+=2;
            }
            else{
                arr[i]=evenCount;
                evenCount+=2;
            }
        }
        for(ll i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}