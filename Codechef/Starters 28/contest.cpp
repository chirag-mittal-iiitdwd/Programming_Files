#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<vector<int>>cnt(n+1,vector<int>(n+1));

        for(int num=1;num<=n;num++){
            for(int deno=1;deno<=n;deno++){
                int gcd=__gcd(num,deno);
                int x=num/gcd;
                int y=deno/gcd;
                cnt[x%y][y]++;  // rem/deno
            }
        }

        int ans=0;

        for(int deno=1;deno<=n;deno++){
            for(int num=0;num<deno;num++){
                ans+=cnt[num][deno]*cnt[(deno-num)%deno][deno];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}