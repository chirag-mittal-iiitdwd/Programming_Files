/*    
    We are given ascending sorted array that has  been 
    rotated from a pivot point (unknown to us) and an 
    element X. Search for X in the array with complexity 
    less than that of linear search

    original array = [10, 20, 30, 40, 50]
    rotated array = [30, 40, 50, 10, 20]
    Rotated about 50

    ---> Strategy : 
    Find the pivot point
    Apply binary search in left half 
    Apply binary search in right half

    ----> Finding pivot
    only element that will be grater than its next element
        arr[i] > arr[i+1] , i <= n-1
    After finding pivot point we search into left and right halves

*/

#include<iostream>
using namespace std;

// recursively checking, if our key is equal to mid or not
int searchInRotatedArray(int arr[],int key,int left,int right){
    if(left>right){
        return -1;
    }
    int mid=(left+right)/2;
    if(arr[mid]==key){
        return mid;
    }

    if(arr[left]<=arr[mid]){
        if(key>=arr[left] && key<=arr[mid]){
            return searchInRotatedArray(arr,key,left,mid-1);
        }
        return searchInRotatedArray(arr,key,mid+1,right);
    }
    else{
        if(key>=arr[mid] && key<=arr[right]){
            return searchInRotatedArray(arr,key,mid+1,right);
        }
        return searchInRotatedArray(arr,key,left,mid-1);
    }
}

int main(){
    int arr[]={6,7,8,9,10,1,2,5};
    int n=8;
    int key=8;
    cout<<searchInRotatedArray(arr,key,0,7);
}