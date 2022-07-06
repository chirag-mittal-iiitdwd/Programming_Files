#include<bits/stdc++.h>
using namespace std;
int t,n;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0;

        for(int i=1;i*i<=n;i++){
            if(n%1==0){
                int div1=i,div2=n/i;
                if(div1==2 || div2==2){
                    ans++;
                }
                else{
                    ans+=2;
                }
            }
        }

        cout<<ans<<endl;
    }
}