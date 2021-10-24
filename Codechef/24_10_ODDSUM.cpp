
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll sum=0;
        if(n<3){
            cout<<1<<endl;
        }
        else{
            n--;
            sum=(n*n)-n+1;
            cout<<sum<<endl;
        }
    }
    return 0;
}