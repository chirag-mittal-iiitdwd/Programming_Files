#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int cur=0;
        int a1,a2;
        cin>>a1>>a2;
        cur=a1+a2;
        cin>>a1>>a2;
        cur=max(cur,a1+a2);
        cin>>a1>>a2;
        cur=max(cur,a1+a2);
        cout<<cur<<endl;
    }
    return 0;
}