/*
    Given an array ans this array contains the size of matriz to be multiplied
    if the size of matrix is n than n-1 matrixes are given
    for dimension of matrix at ith index ---> arr[i-1] * arr[i]
    we have to find the minimum cost or multiplications needed when whey are multiplied

    we will place k at different positions and take the minimum cost

    we will take the index i from 1st position of the array because if we take i as 0 then 
    dimensions = arr[i-1],arr[i] ---> arr[-1],arr[0] (which does not exist)
    we can take j from n-1 index

    the base condition will be if(i>=j) because if i==j meaning there is only one matrix this wont be able to multiply with itself
    i>j is obvious

    now the k will move from k=i to k<=j-1 and break for (i,k) to (k+1,j) because if we take k<=j than the other part wont have any matrix
    there is another method k=i+1 to k<=j and break for (i,k-1) to (k,j) 
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int i,int j){
    if(i>=j){
        return 0;
    }
    int mini=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int tempAns=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        mini=min(tempAns,mini);
    }
    return mini;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,1,n-1);
}