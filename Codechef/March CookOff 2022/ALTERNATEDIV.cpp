#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    int k=1;
    for(int i=0;i<n;i+=2){
        v[i]=k;
        k+=2;
    }

    for(int i=1;i<n;i+=2){
        v[i]=v[i-1]*2;
    }

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}