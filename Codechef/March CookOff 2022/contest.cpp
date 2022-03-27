#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

vector<int> findFactors(int x){
    vector<int>factors;
    for(int i=1;i*i<=x;i++){
        if((x%i)==0){
            factors.push_back(i);
            if((i*i)!=x){
                factors.push_back(x/i);
            }
        }
    }
    return factors;
}

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>factors=findFactors(x);

    for(auto&size:factors){
        if(size<=n){
            for(auto&mini:factors){
                if(size!=mini || size*mini==x){
                    if(mini<=n && (n-mini)==size && size*mini==x){
                        cout<<"YES\n";
                        return;
                    }
                }
            }
        }
    }
    cout<<"NO\n";
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}