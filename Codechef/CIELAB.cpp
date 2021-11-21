#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a,b;
    cin>>a>>b;
    ll minus=a-b;
    if(minus%10==9){
        cout<<minus-1<<endl;
    }
    else{
        cout<<minus+1<<endl;
    }
    return 0;
}