#include<bits/stdc++.h>
using namespace std;
int minSwap(int arr[],int n,int k){
    int maxGrp=INT_MIN;
    int currentGrp=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=k){
            currentGrp++;
            maxGrp=max(maxGrp,currentGrp);
        }
        else{
            currentGrp=0;
        }
    }
    return k-maxGrp;
}

int minSwap1(int *arr, int n, int k) {
    // cout<<"N : "<<n<<" K : "<<k<<endl;
    int count = 0;
    for (int i = 0; i < n; ++i){
        if (arr[i] <= k){
            count++;
        }
    }
    // cout<<"Count : "<<count<<endl;
     
    int bad = 0;
    for (int i = 0; i < count; ++i){
        if (arr[i] > k){
            bad++;
        }
    }
    // cout<<"Bad : "<<bad<<endl;
    
    int ans = bad;
    for (int i = 0, j = count; j < n; ++i, ++j) {
        if (arr[i] > k){
            --bad;
        }
        if (arr[j] > k){
            ++bad;
        }
        // cout<<"Bad : "<<bad<<endl;
        ans = min(ans, bad);
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minSwap(arr,n,k)<<endl;
    cout<<minSwap1(arr,n,k)<<endl;
}