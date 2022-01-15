#include<bits/stdc++.h>
using namespace std;
#define int long long int

int power(int a,int n,int m){
    int ans=1;
    while(n){
        if(n&1){
            ans=(ans*a)%m;
            n--;
        }
        else{
            a=(a*a)%m;
            n/=2;
        }
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
        int a,m;
        cin>>a>>m;
        cout<<"a^-1 = "<<power(a,m-2,m)<<endl;
    }
    return 0;
}