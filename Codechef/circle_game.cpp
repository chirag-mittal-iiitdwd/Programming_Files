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
        int m,x;
        cin>>m>>x;
        m--;
        if(m==0){
            for(int i=1;i<=x;i++){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else{
            int ans[x+1];
            ans[1]=1;
            for(int i=2;i<=x;i++){
                int firstLoser=(m%i)+1;
                if(ans[i-1]<firstLoser){
                    ans[i]=ans[i-1];
                }
                else{
                    ans[i]=ans[i-1]+1;
                }
            }
            for(int i=1;i<=x;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}