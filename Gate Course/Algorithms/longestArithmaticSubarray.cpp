#include<bits/stdc++.h>
using namespace std;

// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bf4ed#problem

int longestArithmaticSubarray(int arr[],int n){
    // In Constraints we are given that 2<=N
    int maxAns;
    int currentDiff=arr[0]-arr[1];
    int currentAns=2;
    maxAns=currentAns;
    for(int i=1;i<n-1;i++){
        if(arr[i]-arr[i+1]==currentDiff){
            currentAns++;
        }
        else{
            currentDiff=arr[i]-arr[i+1];
            currentAns=2;
        }
        maxAns=max(maxAns,currentAns);
    }
    return maxAns;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<longestArithmaticSubarray(arr,n);
}