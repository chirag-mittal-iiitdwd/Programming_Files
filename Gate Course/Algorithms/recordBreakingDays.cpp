#include<bits/stdc++.h>
using namespace std;

// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387171

int recordBreakingDays(int arr[],int n){
    int currentMax;
    int ans;
    if(n==1){
        return 1;
    }
    else{
        int ans=0;
        int maxInPrevious=arr[0];
        if(arr[0]>arr[1]){
            ans++;
        }
        for(int i=1;i<n-1;i++){
            if(arr[i]>maxInPrevious && arr[i]>arr[i+1]){
                ans++;
                maxInPrevious=arr[i];
            }
        }
        if(arr[n-1]>maxInPrevious){
            ans++;
        }
        return ans;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<recordBreakingDays(arr,n)<<endl;
    }
}