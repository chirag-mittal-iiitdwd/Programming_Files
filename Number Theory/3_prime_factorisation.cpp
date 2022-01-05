#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// Time Complexity : sqrt(n)
void primeFactorisation(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            cout<<i<<"^"<<cnt<<endl;
        }
    }
    if(n>1){
        cout<<n<<"^"<<1<<endl;
    }
}

// Using sieve, Time Complexity : O(logN)
// Storing the minimum prime divisor at every index
// Difference is we would run loop till N because every index must have some minimum divisor
// Initially it contains -1
// If we run till sqrt(N) then the primes after sqrt(N) will have -1
int arr[1000001];
void primeFactSieve(){
    int maxN=1000000;
    memset(arr,-1,sizeof(arr));
    arr[1]=1;
    for(int i=2;i<=maxN;i++){
        if(arr[i]==-1){
            for(int j=i;j<=maxN;j+=i){
                if(arr[j]==-1){
                    arr[j]=i;
                }
            }
        }
    }
}

int arr1[1000001];
void primeFactSieveOpti(){
    int maxN=1000000;
    arr1[1]=1;
    for(int i=2;i<=maxN;i++){
        arr[i]=i;
    }
    for(int i=4;i<=maxN;i+=2){
        arr1[i]=2;
    }

    for(int i=3;i*i<maxN;i++){
        if(arr1[i]==i){
            for(int j=i*i;j<maxN;j+=i){
                if(arr1[j]=j){
                    arr1[j]=i;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}