// Given a array we have to find if there exists a subarray with sum equal to a given value

#include<bits/stdc++.h>
using namespace std;

bool subsetSumRec(vector<int>arr,int n,int sum){
    if(sum==0){
        return true;
    }
    if(n==0){
        return false;
    }

    if(arr[n-1]<=sum){
        return (subsetSumRec(arr,n-1,sum-arr[n-1])||subsetSumRec(arr,n-1,sum));
    }
    return subsetSumRec(arr,n-1,sum);
}

int main(){
    vector<int>arr={3,34,4,12,5,2};
    int sum=30;
    cout<<subsetSumRec(arr,arr.size(),sum)<<endl;
}