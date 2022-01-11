#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Solution {
public:
    int titleToNumber(string str) {
        ios_base::sync_with_stdio(false);
        int n=str.length();
        int ans=0;
        int x=0;
        for(int i=n-1;i>=0;i--){
            ans+=((str[i]-'A'+1)*pow(26,x));
            x++;
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