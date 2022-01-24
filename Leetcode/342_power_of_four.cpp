#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

class Solution {
public:
    bool isPowerOfFour(int n) {
        return fmod(log10(n)/log10(4),1)==0;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}