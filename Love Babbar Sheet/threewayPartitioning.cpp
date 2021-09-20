/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void threewayPartition(vector<int>&arr,int a,int b){
    sort(arr.begin(),arr.end());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    threewayPartition(arr,a,b);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}