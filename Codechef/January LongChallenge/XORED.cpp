#include<bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;

        int bits=log2(x)+1;
        int comb=pow(2,bits);
        vector<string>ans(n);
        if(comb<n){
            int bitsTmp=bits+1;
            int combTmp=pow(2,bitsTmp);
            while(combTmp<n){
                bitsTmp++;
                combTmp=pow(2,bitsTmp);
            }
            bool flag=false;
            int extra=bitsTmp-bits;
            for(int i=0;i<extra;i++){
                for(int i=0;i<n;i++){
                    
                }
            }
        }

    }
    return 0;
}