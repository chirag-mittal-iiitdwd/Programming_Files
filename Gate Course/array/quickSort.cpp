/*
    https://www.youtube.com/watch?v=UA_Rmjfj4bw
    for the first element take two pointers i and j
    i = start j=end-1;
    keep moving i forward until you get bigger element than current
    keep moving j backward until you get element smaller than current
    after this swap element  at i and j
    do this till i becomes grater than j
    
    after this swap current and arr[j]
    now make recursive calls for the array forward than pivot and  

    bext case complexity : O(n logn)
    worst case : O(n^2)

    Space complexity : O(1)+O(N) (extra space + recursion stack )

    We can make the average case complexity to O(N logN) by making pivot to arr[(low+high)/2]
    but still there might be some case for which complexity is O(N^2)  
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int partition(int low,int high,int arr[]){
    int i=low,j=high;
    int pivot=arr[low];
    while(i<j){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pivot=partition(low,high,arr);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
    return 0;
}