#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string str;
        cin>>str;
        if(k==1){
            cout<<str<<endl;
        }
        else{
            string x{""};
            ll start=0;
            ll end=k-1;
            ll i=0;
            while(i<k){
                if((i&1)==0){
                    x+=str[start];
                    start++;
                    i++;
                }
                else{
                    x+=str[end];
                    end--;
                    i++;
                }
            }
            reverse(x.begin(),x.end());
            x+=str.substr(k);
            cout<<x<<endl;
        }
    }
    return 0;
}