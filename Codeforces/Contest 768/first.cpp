#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        for(int i=0;i<n;i++){
            if(a[i]<b[i]){
                swap(a[i],b[i]);
            }
        }
        int ans=*max_element(a.begin(),a.end());
        ans*=*max_element(b.begin(),b.end());

        cout<<ans<<endl;
    }
    return 0;
}