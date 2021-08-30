/*
    
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        string ans={};
        ans=next_permutation(a[0].begin(),a[0].end());
        for(int i=1;i<n;i++){
            if(ans==a[i]){
                ans=next_permutation(a[i].begin(),a[i].end());
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}