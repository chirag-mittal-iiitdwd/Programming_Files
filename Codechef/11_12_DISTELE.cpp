#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int solve(int arr[],int n){
    int dp[n];
    dp[0]=1;
    if(n==1){
        return dp[n-1];
    }
    map<int,int>mp;
    mp[arr[0]]=1;
    if(arr[1]==arr[0]){
        mp[arr[0]]=2;
        dp[1]=dp[0];
    }
    else{
        mp[arr[1]]=2;
        dp[1]=dp[0]+2;
    }
    if(n==2){
        return dp[n-1];
    }
    for(int i=2;i<n;i++){
        if(mp[arr[i]]==0){
            dp[i]=dp[i-1]+1;
        }
        else{
            dp[i]=dp[i-1]+1-mp[arr[i]];
            mp[arr[i]]=i+1;
        }
    }
    return dp[n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<solve(arr,n)<<endl;
    }
    return 0;
}