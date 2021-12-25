#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll largestVal(ll arr[]){
    ll ans=INT_MIN;
    do{
        ans=max(ans,(arr[0]-arr[1])*arr[2]);
    } while (next_permutation(arr,arr+3));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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

        ll arr1[3]={arr[0],arr[n-2],arr[n-1]};
        cout<<largestVal(arr1)<<endl;
    }
    return 0;
}