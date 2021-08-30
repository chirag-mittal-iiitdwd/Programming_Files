/*
    We are given with a sum and an integer array
    We have to say if there is any subset present in the array whose sum
    is equal to the given sum or not
*/

#include<bits/stdc++.h>
using namespace std;

bool subsetSumPresent(vector<vector<bool>>arr,int numberArr[],int n,int s){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            if(i==0){
                arr[i][j]=false;
            }
            // j is zero when the sum required is 0
            if(j==0){
                arr[i][j]=true;
            }
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            if(numberArr[i-1]<=j){
                arr[i][j]=((arr[i-1][j-numberArr[i-1]])||(arr[i-1][j]));
            }
            else{
                arr[i][j]=arr[i-1][j];
            }
        }
    }
    return arr[n][s];
} 