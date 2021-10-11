#include<bits\stdc++.h>
using namespace std;

// Preprocessing for Sieve: O(n log log n)
// Time Complexity for factorization: O(log n)
// Space Complexity: O(n)

void sieve(int n){
    int smallestPrimeFactor[n+1]={0};
    for(int i=2;i<=n;i++){
        smallestPrimeFactor[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(smallestPrimeFactor[i]==i){
            for(int j=i;j<=n;j+=i){
                if(smallestPrimeFactor[j]==j){
                    smallestPrimeFactor[j]=i;
                }
            }
        }
    }

    while(n!=1){
        cout<<smallestPrimeFactor[n]<<" ";
        n/=smallestPrimeFactor[n];
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    sieve(n);
}