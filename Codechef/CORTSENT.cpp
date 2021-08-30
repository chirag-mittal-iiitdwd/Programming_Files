#include<iostream>
using namespace std;
void solve(){
    int k;
    cin>>k;
    bool ans=true;
    for(int i=0;i<k;i++){
        string s;
        cin>>s;
        if(ans){
            bool first=false,second=false;
            for(auto ch:s){
                if(ch>='a' && ch<='m'){
                    first=true;
                }
                else if(ch>='N' && ch<='Z'){
                    second=true;
                }
                else{
                    ans=false;
                }
            }
            if(first!=second){
                ans=true;
            }
            else{
                ans=false;
            }
        }
    }
    if(ans){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}