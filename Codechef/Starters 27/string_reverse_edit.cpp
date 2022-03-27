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
        string str;
        cin>>str;
        string rev=str;
        reverse(rev.begin(),rev.end());

        int n=str.size(),j=0,ans=0,i=0;
        while(i<n){
            if(str[i]==rev[j]){
                j++;
            }
            else{
                ans++;
            }
            i++;
        }

        cout<<ans<<endl;
    }
    return 0;
}