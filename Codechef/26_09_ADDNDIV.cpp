
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if(a==1 || b==1){
            cout<<"YES"<<endl;
        }
        else if(__gcd(a,b)==1){
            cout<<"NO"<<endl;
        }
        else{
            // ll pwr=b;
            // while(true){
            //     double ans1=(double)pwr/(double)a;
            //     ll ans2=pwr/a;
            //     // cout<<ans1<<" "<<ans2<<endl;
            //     if(ans1==ans2){
            //         cout<<"YES"<<endl;
            //         break;
            //     }
            //     pwr=pwr*b;
            // }
            cout<<"YES"<<endl;
        }
    }
    return 0;
}