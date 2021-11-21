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
        int n;
        cin>>n;
        int x=1e5;
        for(int i=0;i<n;i++){
            cout<<x<<" ";
            x--;
        }
        cout<<endl;
    }
    return 0;
}