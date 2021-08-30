/*
    For a given array and integers K and X, find the maximum sum 
    subarray of size K and having sum less than X.

    -----> Approach 1
        Compute sum of all possible subarrays of size K
        Than comparing and giving answer

        The time complexity of this approach will be O(n*k)
    -----> Approach 2
        1. Calculate sum of first K elements
        2. Initialize ans with this sum
        3. Iterate over the rest of the array
           Keep adding one element in sum and removing one from 
           start, Compare new sum with ans in each iteration
        The time compexity of this approach is O(n), actually it is 
        2*O(n) but since we ignore constants so it id O(n)
*/
#include<iostream>
using namespace std;
void maxSubarraySum(int arr[],int n,int k,int x){
    int sum=0,ans=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    if(sum<x){
        ans=sum;
    }
    for(int i=k;i<n;i++){
        sum-=arr[i-k];
        sum+=arr[i];
        if(sum<x){
            ans=max(ans,sum);
        }
    }
    cout<<ans<<" is the maximum subarray sum less than "<<x<<"\n";
}

int main(){
    int arr[]={7,5,4,6,8,9};
    int k=3;
    int x=20;
    int n=6;
    maxSubarraySum(arr,n,k,x);
}