/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int maximumSubarraySum(int arr[],int n){
    int currentSum=0;
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        currentSum+=arr[i];
        if(maxSum<currentSum){
            maxSum=currentSum;
        }
        if(currentSum<0){
            currentSum=0;
        }
    }
    return maxSum;
}

int smallestSubarrayWithSumGreaterThanX(int arr[],int n,int x){
    int left=0;
    int right=0;
    int currentSum=0;
    int minSize=INT_MAX;
    int currentSize=0;
    for(int i=0;i<n;i++){
        currentSize++;
        currentSum+=arr[i];
        right++;
        if(currentSum>x){
            minSize=min(minSize,currentSize);
            while(currentSum>x && right>left){
                currentSum-=arr[left];
                left++;
                currentSize--;
            }
            currentSum+=arr[left-1];
            left--;
            currentSize++;
            minSize=min(currentSize,minSize);
        }
    }
    return minSize;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<smallestSubarrayWithSumGreaterThanX(arr,n,x);
    return 0;
}