#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        n--;
        ll cnt=0;
        for(ll i=1;i*i<n;i++){
            if(n%i==0){
                cnt+=2;
            }
        }
        if(pow(sqrt(n),2)==n){
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}