/* 
    we have to assign signs on each element of the array and find by how
    many ways we can make that sum equal to the given value

    Same as Count The Number Of Subset with A Given Difference
*/
#include<bits/stdc++.h>
using namespace std;

int targetSum(int arr[],int n,int req){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int findSum=(sum+req)/2;
    int t[n+1][findSum];
    for(int i=0;i<=sum;i++){
        t[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        t[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=findSum;i++){
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
    int n,req;
    cin>>n>>req;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<targetSum(arr,n,req);
}