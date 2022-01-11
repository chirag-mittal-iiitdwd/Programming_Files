#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int primeFact1(int n){
    if(n==1){
        return 0;
    }
    int ans=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            ans++;
        }
    }

    if(n>1){
        ans++;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(m==1){
            cout<<0<<endl;
        }
        else if(n==1){
            cout<<1<<endl;
        }
        else{
            int k=primeFact1(m);
            while((n%k)!=0){
                k--;
            }
            cout<<k<<endl;
        }
    }
    return 0;
}