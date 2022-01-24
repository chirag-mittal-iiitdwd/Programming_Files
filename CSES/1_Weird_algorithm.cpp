#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    while(n!=1){
        cout<<n<<" ";
        if(n&1){
            n=n*3+1;
        }
        else{
            n/=2;
        }
    }
    cout<<1<<endl;
    return 0;
}