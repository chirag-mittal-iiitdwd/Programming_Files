/*
    We need to return true or false 
    if there exists two sets with sum equal to a given sum

    Now the first thing here is if array sum is odd than we would
    simply return false

    Now find if the sum of one subset is equal to sum because the
    other will automatically be the sum
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

bool subsetSum(vector<vector<bool>>t,int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2!=0){
        return false;
    }
    else{
        return subsetSumPresent(t,arr,n,sum/2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}