#include<bits/stdc++.h>
using namespace std;

int maxConsequetiveOnes(vector<int>arr,int k){
    int zeroCnt=0,i=0,ans=0;
    int n=arr.size();
    for(int j=0;j<n;j++){
        if(arr[j]==0){
            zeroCnt++;
        }
        while(zeroCnt>k){
            if(arr[i]==0){
                zeroCnt--;
            }
            i++;
        }
        ans=max(ans,j-i+1);
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxConsequetiveOnes(arr,k);
}