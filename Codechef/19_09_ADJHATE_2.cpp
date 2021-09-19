#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll findAndReplace(ll arr[],ll n,ll position,ll oddOrEven){
    for(ll i=position+1;i<n;i++){
        if((arr[i]%2)!=oddOrEven){
            swap(arr[position],arr[i]);
            return 1;
        }
    }
    return -1;
}

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
        sort(arr,arr+n);
        ll p=0;
        for(ll i=0;i<n-1;i++){
            if((arr[i]%2)==(arr[i+1]%2)){
                ll x=findAndReplace(arr,n,i+1,arr[i]%2);
                if(x!=1){
                    p=-1;
                    break;
                }
            }
        }
        if(p==-1){
            cout<<-1<<endl;
        }
        else{
            ll sum=0;
            for(ll i=0;i<n-1;i++){
                sum+=abs(arr[i]-arr[i+1]);
            }
            if(sum%2){
                for(ll i=0;i<n;i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
    }
    return 0;
}