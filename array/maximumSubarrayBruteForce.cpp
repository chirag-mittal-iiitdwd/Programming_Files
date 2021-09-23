#include<bits/stdc++.h>
using namespace std;

int maximumSubarray(int arr[],int n){
    int sum=0;
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            maxSum=max(maxSum,sum);
        }
    }
    return maxSum;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maximumSubarray(arr,n);
}