#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

class Solution {
public:
    bool isPowerOfThree(int n) {
        while((n%3)==0){
            n/=3;
        }
        return n==1;
    }
};

class Solution{
    public:
    bool isPowerOfThree(int n){
        return fmod(log10(n)/log10(3),1)==0;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}