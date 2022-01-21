/*
    At max any number can have log(N) primes, log is base 10
    1. Since N does not change, we can calculate the prime factorisation of N only once
    2. Using each prime P in prime factorisation of N, factorize K. In this operation the 
       outer loop will run till log(N)*logP(N) where p is the individual prime
    3. Now calculate minimum of the powers of K and N

    then finally multiplying the minimum of the powers and returning the answer
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}