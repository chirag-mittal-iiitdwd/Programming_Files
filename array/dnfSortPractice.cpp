#include<bits/stdc++.h>
using namespace std;

void dnfSort(int arr[],int n){
    int i=0;
    int k=0;
    int j=n-1;
    while(k<j){
        if(arr[k]==0){
            swap(arr[i],arr[k]);
            k++;
            i++;
        }
        else if(arr[k]==1){
            k++;
        }
        else{
            swap(arr[k],arr[j]);
            j--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dnfSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}