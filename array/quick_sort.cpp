#include<bits/stdc++.h>
using namespace std;

// int partition(int arr[],int low,int high){
//     int pivot=arr[low];
//     int i=low;
//     for(int j=low+1;j<high;j++){
//         if(arr[j]>pivot){
//             j++;
//         }
//         else{
//             i++;
//             swap(arr[i],arr[j]);
//         }
//     }
//     swap(arr[i],pivot);
//     return i;
// }

int partition (int arr[], int low, int high) { 
    int pivot = arr[high];
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j < high; j++){ 
        if (arr[j] < pivot){ 
            i++;
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[],int low,int high){
    if(low<high){
        int q=partition(arr,low,high);
        quickSort(arr,low,q-1);
        quickSort(arr,q+1,high);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}