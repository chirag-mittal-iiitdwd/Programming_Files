#include"bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int zeroCount=0;
    int i=0;
    int ans=0;
    for(int j=0;j<n;j++){
        if(a[j]==0){
            zeroCount++;
        }
        while(zeroCount>k){
            if(a[i]==0){
                zeroCount--;
            }
            i++;
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans;
}