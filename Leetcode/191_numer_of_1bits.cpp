#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n){
            n=(n&(n-1));
            cnt++;
        }
        return cnt;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}