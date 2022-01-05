#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int is_prime[1000001];

// Time Complexity : O(n.loglogn)
void sieve(){
    int maxN=1000000;
    for(int i=0;i<=maxN;i++){
        is_prime[i]=1;
    }
    is_prime[0]=is_prime[1]=0;
    for(int i=2;i*i<=maxN;i++){
        if(is_prime[i]==1){
            for(int j=i*i;j<=maxN;j+=i){
                is_prime[j]=0;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    sieve();
    cout<<is_prime[45]<<endl;
}