#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=1;i<=n;i++){
            ans[i]=ans[i&(i-1)]+1;
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