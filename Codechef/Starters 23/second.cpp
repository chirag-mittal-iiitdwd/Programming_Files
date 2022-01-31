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
        int n,k,x;
        cin>>n>>k>>x;
        if(x>k){
            cout<<-1<<endl;
        }
        else{
            int cnt=0;
            for(int i=0;i<n;i++){
                if(cnt==x){
                    cnt=0;
                }
                cout<<cnt<<" ";
                cnt++;
            }
            cout<<endl;
        }
    }
    return 0;
}