#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007


void solve(){
    int n,q;
    cin>>n>>q;
    string a,b;
    cin>>a>>b;
    cout<<n<<" "<<q<<" "<<a<<" "<<b<<endl;

    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<l<<" "<<r<<endl;
        
        int size=r-l+1;
        cout<<"i : "<<i;
        string tempA=a.substr(l-1,size);
        string tempB=b.substr(l-1,size);
        cout<<"tempA : "<<tempA<<" tempB : "<<tempB<<endl;
        if(size==1 || tempA==tempB){
            cout<<"YES\n";
            return;
        }
        for(int j=0;j<size;j++){
            if(tempA[j]>=tempB[j]){
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}