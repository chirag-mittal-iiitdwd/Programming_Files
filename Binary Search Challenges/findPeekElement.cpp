/*
    For a given array, find the peek element in the array.
    Peak element is one which is greater than both, lft and
    right neighbours of itself

    ---> Corner cases
    Ascending array : last element is peak
    Descending array : last element is peak
    For all same elements : each element is peak

    Example : arr[] = [10 ,20 ,15 ,2 ,23 ,90 ,67 ]
                           ^              ^
    Use binary search, analyze indices from 0 to n-1
    Compute mid and for each mid check if arr[mid] is peak or not

    Else if arr[mid-1] > arr[mid]
    check left for peak  ----> end = mid

    else if arr[mid] < arr[mid+1]
    check roght for peak
*/

#include<iostream>
using namespace std;

int findPeakElement(int arr[],int low,int high,int n){
    // low and high fedine the start and end of the array
    int mid = low+(high-low)/2;
    // Sometimes mid exceeds the integer due to high + low so we use
    // this as our mid
    if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid])){
        // Here if we get mid as zero than we wont be able to get arr[mid-1]
        // So we check only mid == 0

        // Also if we get mid as n-1 than we we wont bw able to get arr[mid+1]
        // So we check only mid == n-1
        return mid;
    }
    else if(mid>0 && arr[mid-1]>arr[mid]){
        return findPeakElement(arr,low,mid-1,n);
    }
    else{
        return findPeakElement(arr,mid+1,high,n);
    }
}

int main(){
    int arr[]={10 ,20 ,15 ,2 ,23 ,90 ,67};
    cout<<findPeakElement(arr,0,6,7);
}