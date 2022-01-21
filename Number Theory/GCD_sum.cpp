#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

int phi[1000001];
void init(){
    for(int i=0;i<=1000000;i++){
        phi[i]=i;
    }

    for(int i=2;i<=1000000;i++){
        if(phi[i]==i){
            for(int j=i;j<=100000;j+=i){
                phi[j]*=(i-1);
                phi[j]/=i;
            }
        }
    }
}

int getCount(int d,int n){
    return phi[n/d];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int res=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                int d1=i;
                int d2=n/i;
                res+=d1*getCount(d1,n);
                if(d1!=d2){
                    res+=d2*getCount(d2,n);
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}