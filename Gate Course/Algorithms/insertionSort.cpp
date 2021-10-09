#include<bits/stdc++.h>
using namespace std;

/*  
    Inplace sorting algorithm : Property of sorting algorithm
        Means that we are not using any extra space for the algorithm to work
        This is true for insertion sort
    
    Stable Sort : Property of sorting algorithm
        Means that if the ordering of the elements is preserved in the sorted array - Stable
        True in case of Insertion Sort

    Time Complexity Analysis :
        Best Case : O(N)
        Worst Case : O(N^2)
    
    Space Compleity : O(1)
*/

void insertionSort(int arr[],int n){
    int smallIdx=-1;
    for(int i=1;i<n;i++){
        int current=arr[i];
        int j=i-1;
        
        /* Comparing the element at ith position with all the previous elements
        If at any place we find that the elents previous to this current element are greater 
        Than we take uptill what point they are greater and than finally swap with the
        last position where the element was found greater

        The algorithm is called insertion sort because we are inserting the elemets to their correct locations
        */
        while((arr[j]>current) && (j>=0)){
            smallIdx=j;
            j--;
        }
        if(smallIdx!=-1){
            swap(arr[i],arr[smallIdx]);
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
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}