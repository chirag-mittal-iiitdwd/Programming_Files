/*
    We have stored INT_MAX-1 during initialiazation because
    when we add 1 it becomes INT_MAX and does not go out of bound
*/
#include<bits/stdc++.h>
using namespace std;

int coinMinimumCoins(int coins[],int n,int sum){
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++){
        t[i][0]=0;
    }
    for(int i=0;i<=sum;i++){
        t[0][i]=INT_MAX-1;
    }
    // for(int i=1;i<=sum;i++){
    //     if(i%coins[0]==0){
    //         t[1][i]=i/coins[0];
    //     }
    //     else{
    //         t[1][i]=INT_MAX-1;
    //     }
    // }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coins[i-1]>j){
                t[i][j]=t[i-1][j];
            }
            else{
                t[i][j]=min(t[i-1][j],1+t[i][j-coins[i-1]]);
            }
        }
    }
    return t[n][sum];
}

int main(){
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<coinMinimumCoins(arr,n,sum)<<endl;

    return 0;
}