#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

// Time Complexity : O(sqrt(N))
int phi(int n){
    int ans=n;
    for(int i=2;i<=n;i++){
        if((n%i)==0){
            while((n%i)==0){
                n/=i;
            }
            ans*=(i-1);
            ans/=i;
        }
    }
    if(n>1){
        ans*=(n-1);
        ans/=n;
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<phi(n)<<endl;
    }
    return 0;
}