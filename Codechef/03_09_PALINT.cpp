#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        int operations=0;
        for(int i=0;i<n;i++){
            int xorVal=arr[i]^x;
            cout<<xorVal<<endl;
            if(m[xorVal]>=m[arr[i]]){
                operations++;
                arr[i]=xorVal;
            }
        }
        int maxDup=INT_MIN;
        for(auto it:m){
            maxDup=max(it.second,maxDup);
        }
        cout<<maxDup<<" "<<operations<<endl;
    }
    return 0;
}