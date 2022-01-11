#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(N)
bool is_prime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i<n;i++){
        if((n%i)==0){
            return false;
        }
    }

    return true;
}

// Based on the fact that if the number is divisible by any number less than the sqrt(n) than its not a prime
// Because the divisors always exists in pairs one will be above sqrt(n) and other will be below sqrt(n)
// Thus if we check for one of them then other is automatically checked

bool is_prime_opti(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if((n%i)==0){
            return false;
        }
    }

    return true;
}

int main(){

}