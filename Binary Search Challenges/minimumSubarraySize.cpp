/*
    For a given array and an integer X, find the minimum subarray size for
    which sum > X

    --> Compute sum of all subarrays and check the condition
        Time Complexity = O(n^2)

    --> Sliding window approach
        Use variables ans, sum and start
        ans represent the minimum subarray size
        sum is the current sum
        start is the starting point of the subarray

        Iterate over array and start adding elements to sum
        if sum > X, remove elements from the start

        Time Complexity = O(n)
*/

#include<iostream>
using namespace std;

int smallestSubarrayWithSum(int arr[],int n,int x){
    int sum=0,minLength=n+1,start=0,end=0;
    while(end<n){
        while(sum<=x && end<n){
            sum+=arr[end++];
        }
        while(sum>x && start<n){
            if(end-start<minLength){
                minLength=end-start;
            }
            sum-=arr[start++];
        }
    }

    return minLength;
}

int main(){
    int arr[]={1,4,45,6,10,19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x=51;
    cout<<smallestSubarrayWithSum(arr,n,x);
}