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
        int n;
        cin>>n;
        int requiredSum=pow(2,n);
        if(n==1){
            cout<<"1 1"<<"\n";
        }
        else{
            int i;
            for(i=1;i<n;i++){
                cout<<i<<" ";
            }
            ll p=pow(2,n);
            cout<<i-1<<" "<<p-n*(n+1)/2+1<<"\n";
        }
    }
    return 0;
}