/*
    The bubble sort gets its name because elements tend to 
    move up into the correct order like bubbles rising to the surface.

    Inplace Algorithm
    Stable Algorithm

    Time Complexity : O(N^2)
    Space Complexity : O(1)
*/

#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
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
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}