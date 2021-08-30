/*
    The Difference of sum of two subsets must be equal to given difference

    Sum(s1) - Sum(s2) = diff
    Sum(s1) + Sum(s2) = sum(arr)

    Adding Both ---->  sum(s1) = (diff + sum(arr))/2
    Now this problem is, count of subset sum
*/

#include<bits/stdc++.h>
using namespace std;

int countSubsetsWithGivenDiff(int arr[],int n,int diff){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int findSum=(diff+sum)/2;
    int t[n+1][findSum+1];
    for(int i=0;i<=findSum;i++){
        t[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        t[i][0]=1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<findSum+1;j++){
            if(arr[i-1]>j){
                t[i][j]=t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j]+t[i-1][j-arr[i-1]];
            }
        }
    }
    return t[n][findSum];
}

int main(){
    int arr[]={1,1,2,3};
    int n=4;
    int diff=1;
    cout<<countSubsetsWithGivenDiff(arr,n,diff)<<endl;
}