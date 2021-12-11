#include<bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution {
    int mod=1e9+7;
    ll lcm(ll a,ll b){
        return (a*b)/__gcd(a,b);
    }
    public:
    int nthMagicalNumber(int n, int a, int b) {
        ll low,high,mid,target;
        ll lcmab=lcm(a,b);
        low=min(a,b);
        high=low*n;
        while(low<high){
            mid=low+((high-low)/2);
            target=(mid/a)+(mid/b)-(mid/lcmab);
            if(target<n){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return high%mod;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        Solution obj;
        cout<<obj.nthMagicalNumber(n,a,b)<<endl;
    }
}