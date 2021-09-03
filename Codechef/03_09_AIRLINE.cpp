#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll arr[3];
        ll d,e;
        for(int i=0;i<3;i++){
            cin>>arr[i];
        }
        cin>>d>>e;
        sort(arr,arr+3);
        if((arr[0]<=e) && (arr[1]+arr[2]<=d)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}