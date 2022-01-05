#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string str;
        cin>>str;
        int ans=0;
        int xo=0;
        for(int i=0;i<=n-k;i++){
            xo^=(str[i]-'0');
        }
        if(xo==1){
            ans++;
        }
        int inBeg=0,inEnd=n-k+1;

        while(inEnd<n){
            xo^=(str[inBeg++]-'0');
            xo^=(str[inEnd++]-'0');
            if(xo==1) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}