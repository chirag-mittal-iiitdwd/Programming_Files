#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

// Initially marking the number with itself in the sieve array
// Traversing from i=2
// Dividing the multiples of i with i
// Multiplying the same with i-1
int phi[1000001];
void init(){
    for(int i=0;i<=1000000;i++){
        phi[i]=i;
    }

    for(int i=2;i<=1000000;i++){
        if(phi[i]==i){
            for(int j=i;j<=1000000;j+=i){
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<phi[n]<<endl;
    }
    return 0;
}