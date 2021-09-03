#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        int time=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                time+=a;
            }
            else{
                time+=b;
            }
        }
        cout<<time<<endl;
    }
    return 0;
}