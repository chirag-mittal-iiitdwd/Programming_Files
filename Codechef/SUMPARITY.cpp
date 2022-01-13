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
        int n,a;
        cin>>n>>a;
        if(a&1){
            if(n&1){
                cout<<"Odd"<<endl;
            }
            else{
                cout<<"Even"<<endl;
            }
        }
        else{
            if(n==1){
                cout<<"Even"<<endl;
            }
            else{
                cout<<"Impossible"<<endl;
            }
        }
    }
    return 0;
}