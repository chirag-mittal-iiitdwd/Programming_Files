#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

// Time " O(sqrt(N))"
int divisors(int n){
    int ans=1;
    for(int i=2;i*i<=n;i++){
        if((n%i)==0){
            int powers=0;
            int cur=i;
            while((n%i)==0){
                n/=i;
                powers++;
            }
            ans=(ans*(powers+1));
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
        int n;
        cin>>n;
        cout<<divisors(n)<<endl;
    }
    return 0;
}