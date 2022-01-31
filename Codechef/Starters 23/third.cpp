#include<bits/stdc++.h>
using namespace std;
// #define int long long int
#define mod 1000000007

int calVacations(string str,int i,int x,int n){
    if(i!=-1){
        str[i]='0';
    }
    int cur=0,total=0;
    for(int i=0;i<n;i++){
        if(str[i]=='0'){
            cur++;
        }
        else{
            total+=(cur/x);
            cur=0;
        }
    }
    total+=(cur/x);
    return total;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        string str;
        cin>>str;
        int ans=calVacations(str,-1,x,n);
        for(int i=0;i<n;i++){
            if(str[i]=='1'){
                ans=max(ans,calVacations(str,i,x,n));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}