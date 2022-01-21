#include<bits/stdc++.h>
using namespace std;
// #define int long long int
#define mod 1000000007

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=0;i<=31;i++){
            bool x=n&(1<<31-i);
            ans=ans|(x<<i);
        }
        return ans;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}