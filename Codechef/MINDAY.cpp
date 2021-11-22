/*
    
*/
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
        int n,x;
        cin>>n>>x;
        int div=n/x;
        if(n%x){
            cout<<div+1<<endl;
        }
        else{
            cout<<div<<endl;
        }
    }
    return 0;
}