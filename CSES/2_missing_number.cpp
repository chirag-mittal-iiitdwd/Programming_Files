#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n-1;i++){
        int x;
        cin>>x;
        ans=ans^i^x;
    }
    ans=ans^n;
    cout<<ans<<endl;
    return 0;
}