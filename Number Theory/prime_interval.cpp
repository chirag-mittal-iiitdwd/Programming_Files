#include<bits/stdc++.h>
using namespace std;

int is_prime[10001];
void sieve(){
    for(int i=2;i<10001;i++){
        is_prime[i]=1;
    }
    is_prime[0]=is_prime[1]=0;
    for(int i=2;i*i<=10000;i++){
        if(is_prime[i]==1){
            for(int j=i*i;j<=1000;j++){
                is_prime[j]=0;
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        int cnt=0;
        for(int i=l;i<=r;i++){
            if(is_prime[i]==1){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
}