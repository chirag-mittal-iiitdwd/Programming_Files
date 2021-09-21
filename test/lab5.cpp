#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int current=arr[i];
        int j=i-1;
        while(arr[j]<current && j>=0){
            arr[j+1]=arr[j]; // Putting the smaller value forward
            j--;
        }
        arr[j+1]=current;
    }
}

int main(){
    int arr[]={1,-1,9,4,8};
    int n=5;
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}