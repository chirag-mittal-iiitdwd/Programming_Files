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
        string ans;
        int num=n/26;
        int rem=n%26;

        for(int i=0;i<num;i++){
            for(int j=0;j<26;j++){
                ans+=((char)97+j);
            }
        }
        for(int i=0;i<rem;i++){
            ans+=((char)97+i);
        }

        cout<<ans<<endl;
    }
    return 0;
}