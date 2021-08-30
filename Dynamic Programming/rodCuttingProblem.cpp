/*
    Now this problem is exactly similar to the previous problem ie.
    unbounded knapsack.
    Just the names of the variables have changed
*/ 
#include<bits/stdc++.h>
using namespace std;

int rodCuttingForMaxProf(int price[],int n,int length1[]){
    int len=n;
    int t[n+1][len+1];
    for(int i=0;i<n+1;i++){
        t[i][0]=0;
    }
    for(int i=0;i<len+1;i++){
        t[0][i]=0;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<len+1;i++){
            if(length1[i-1]>j){
                t[i][j]=t[i-1][j];
            }
            else{
                t[i][j]=max(price[i-1]+t[i][j-length1[i-1]],t[i-1][j]);
            }
        }
    }
    return t[n][len];
}

int main(){
    int price[]={5,6,7,8};
    int length1[]={1,2,3,4};
    int n=4;
    cout<<rodCuttingForMaxProf(price,n,length1);
}