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
        int g;
        cin>>g;
        while(g--){
            int i,n,q;
            cin>>i>>n>>q;
            if(i==q){
                cout<<n/2<<endl;
            }
            else{
                cout<<n-(n/2)<<endl;
            }
        }
    }
    return 0;
}