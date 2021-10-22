#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[],int l,int h,int k){
    if(l<h){
        int mid=(l+h)/2;
        if(arr[mid]==k){
            return true;
        }
        else if(arr[mid]>k){
            return binarySearch(arr,l,mid-1,k);
        }
        else{
            return binarySearch(arr,mid+1,h,k);
        }
    }
    return false;
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<binarySearch(arr,0,n-1,k);
}