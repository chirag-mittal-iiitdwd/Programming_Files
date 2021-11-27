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
        int s,a,b,c;
        cin>>s>>a>>b>>c;
        c=float(c);
        float per=c/(float)100;
        float finalAmt=s+s*per;
        // cout<<finalAmt<<endl;
        if(finalAmt>=a && finalAmt<=b){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
}