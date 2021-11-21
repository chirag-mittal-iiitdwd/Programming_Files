#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void getPairsMerge(ll arr[],ll l,ll r,ll mid,ll& minDiff){
    ll b[l+r+1],i=l,k=l,j=mid+1;
    while(i<=mid && j<=r){
        if(arr[i]>arr[j]){
            b[k]=arr[j];
            minDiff=min(minDiff,abs(arr[i]-arr[j]));
            k++;
            j++;
        }
        else{
            minDiff=min(minDiff,abs(arr[i]-arr[j]));
            b[k]=arr[i];
            i++;
            k++;
        }
    }
 
    while(i<=mid){
        b[k]=arr[i];
        i++;
        k++;
    }
    while(j<=r){
        b[k]=arr[j];
        j++;
        k++;
    }
 
    for(ll x=l;x<=r;x++){
        arr[x]=b[x];
    }
}
 
void getAllPairs(ll arr[],ll l,ll r,ll&minDiff){
    if(l<r){
        ll mid=(l+r)/2;
        getAllPairs(arr,l,mid,minDiff);
        getAllPairs(arr,mid+1,r,minDiff);
        getPairsMerge(arr,l,r,mid,minDiff);
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll minDiff=INT_MAX;
        getAllPairs(arr,0,n-1,minDiff);
        cout<<minDiff<<endl;
    }
}
