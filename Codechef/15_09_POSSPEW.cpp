#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        k=k-1;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        for(ll i=0;i<k;i++){
            for(ll j=0;j<n;j++){
                if(arr[j]>0){
                    if(j==0){
                        arr[n-1]++;
                        arr[1]++;
                    }
                    else if(j==(n-1)){
                        arr[n-2]++;
                        arr[0]++;
                    }
                    else{
                        arr[j-1]++;
                        arr[j+1]++;
                    }
                }
            }
            for(ll j=0;j<n;j++){
                cout<<arr[j]<<" ";
            }
            cout<<endl;
        }
        ll sum=0;
        for(ll i=0;i<n;i++){
            sum+=arr[i];
        }
        cout<<sum<<"\n";
    }
    return 0;
}