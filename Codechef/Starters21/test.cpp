#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;
    // cin>>t;
    // while(t--){
    //     int a,b;
    //     cin>>a>>b;
    //     int x=a&b;
    //     cout<<x<<endl;
    // }
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans|=arr[i];
    }
    cout<<ans<<endl;
    return 0;
}