#include<bits/stdc++.h>
using namespace std;

int coinChangeMax(int coin[],int n,int sum){
    int t[n+1][sum+1];
    for(int i=0;i<sum+1;i++){
        t[0][i]=0;
    }
    for(int i=0;i<n+1;i++){
        t[i][0]=1;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]>j){
                t[i][j]=t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j]+t[i][j-(coin[i-1])];
            }
        }
    }
    return t[n][sum];
}

int main(){
    int arr[3]={1,2,3};
    int n=3;
    int sum=5;
    cout<<coinChangeMax(arr,n,sum);
}