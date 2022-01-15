#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
int arr[1000001];

// Time : Log(mod-2)
int invMod(int a){
    int n=mod-2;
    int ans=1;
    while(n){
        if(n&1){
            ans=(ans*a)%mod;
            n--;
        }
        n/=2;
        a=(a*a)%mod;
    }
    return ans;
}

int C(int n,int k){
    if(k>n){
        return 0;
    }
    if(k==n){
        return 1;
    }
    int res=arr[n];
    res=(res*invMod(arr[k]))%mod;
    res=(res*invMod(arr[n-k]))%mod;
    return res;
}

// Time : O(1000001)+O(t*Log(mod-2));
// log(mod-2) = 29
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arr[0]=arr[1]=1;
    for(int i=2;i<=1000000;i++){
        arr[i]=(arr[i-1]*i)%mod;
    }
    int t;
    int n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<C(n,k)<<endl;
    }
    return 0;
}