#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void countPeaks(vector<int>&v,int&ans,int&n,int x=0){
    if(x==n){
        for(int i=1;i<n-1;i++){
            if(v[i-1]>v[i] && v[i]<v[i+1]){
                ans++;
            }
            else if(v[i-1]<v[i] && v[i]>v[i+1]){
                ans++;
            }
        }
        return;
    }
    for(auto num:{0,1,2}){
        v[x]=num;
        countPeaks(v,ans,n,x+1);
    }
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
        vector<int>v(n);
        int ans=0;
        countPeaks(v,ans,n);
        cout<<ans<<endl;
    }
    return 0;
}