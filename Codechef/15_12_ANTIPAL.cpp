#include<bits/stdc++.h>
#define ll long long int
using namespace std;

string createString(int n){
    string ans{""};
    for(int i=0;i<n;i++){
        if(i&1){
            ans+='0';
        }
        else{
            ans+='1';
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1 || n&1){
            cout<<-1<<endl;
        }
        else{
            cout<<createString(n)<<endl;
        }
    }
    return 0;
}