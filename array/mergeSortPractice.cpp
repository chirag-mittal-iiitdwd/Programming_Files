#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int r,int mid){
    int b[l+r+1];
    int k=l;
    int i=l;
    int j=mid+1;
    while(i<=mid && j<=r){
        if(arr[i]>arr[j]){
            b[k]=arr[j];
            k++;
            j++;
        }
        else{
            b[k]=arr[i];
            k++;
            i++;
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

    for(int x=l;x<=r;x++){
        arr[x]=b[x];
    }
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,r,mid);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}