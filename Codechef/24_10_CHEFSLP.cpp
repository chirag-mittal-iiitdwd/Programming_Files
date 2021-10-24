/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,l,x;
        cin>>n>>l>>x;
        int r=n-l;
        int pairs=min(l,r);
        cout<<x*pairs<<endl;
    }
    return 0;
}