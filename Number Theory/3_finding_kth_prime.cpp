#include<bits/stdc++.h>
using namespace std;

bool arr[86028122];
vector<int>primes;
void sieve(){
    int maxN=86028121;
    arr[0]=arr[1]=true;
    for(int i=2;i*i<=maxN;i++){
        if(arr[i]==false){
            for(int j=i*i;j<=maxN;j+=i){
                arr[j]=true;
            }
        }
    }
    for(int i=2;i<=maxN;i++){
        if(!arr[i]){
            primes.push_back(i);
        }
    }
}

int main(){
    sieve();
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        cout<<primes[k-1]<<endl;
    }
}