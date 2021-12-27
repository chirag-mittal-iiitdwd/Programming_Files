#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>arr(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll ans=0;
        vector<ll>cpy=arr;
        sort(cpy.begin(),cpy.end());
        ll maxVal=(cpy[n-1]-cpy[0]);
        vector<int>dp(n,0);

        ll i=0;
        while(i<n-1){
            if(arr[i]==cpy[i]){
                i--;
                continue;
            }
            ll pos=(find(arr.begin(),arr.end(),cpy[i])-(arr.begin()));
            ll curGra=arr[pos];
            ll smallest=curGra;
            for(ll j=pos+1;j<=i;j++){
                smallest=min(smallest,arr[j]);
            }
            ll j=pos-1;
            for(j=pos-1;j>=0;j--){
                if(arr[j]>curGra){
                    break;
                }
            }
            sort(arr.begin()+j+1,arr.end()-(n-i-1));
            dp[i]=(arr[i]-arr[j+1]);
            i=j+1;
        }
        ans=accumulate(dp.begin(),dp.end(),0);
        cout<<min(ans,maxVal)<<endl;
    }
    return 0;
}