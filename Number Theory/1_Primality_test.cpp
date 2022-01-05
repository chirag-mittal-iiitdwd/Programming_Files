#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// Native Approach : Time Complexity : O(N)
bool isPrime(int n){
    if(n==1){
        return false;
    }
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

// This can be easily prooved that when we factorise a number it has two factors
// One has to be <=sqrt(n) and the other above sqrt(n)
// So here we can run a for loop till sqrt(n) and check for prime
// Time Complexity : O(sqrt(N))
bool isPrimeOptimised(int n){
    if(n==1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}