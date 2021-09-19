#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve(){
    ll n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n>4){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        if(i%4==0)
            cout<<arr[i]<<" 0\n";
        else if(i%4==1)
            cout<<"0 "<<arr[i]<<endl;
        else if(i%4==2)
            cout<<-arr[i]<<" 0\n";
        else
            cout<<"0 "<<-arr[i]<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}