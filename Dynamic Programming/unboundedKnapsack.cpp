/*
    The difference is we can include one thing multiple times 
    like we take one flour bag and 3-4 maggie packs from mall
    depending upon our desire 
*/
#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int wt[],int val[],int n,int w){
    int t[n+1][w+1];
    for(int i=0;i<=n;i++){
        t[0][i]=0;
    }
    for(int i=0;i<=w;i++){
        t[i][0]=0;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<=w;j++){
            if(wt[i]>j){
                t[i][j]=t[i-1][j];
            }
            else{
                t[i][j]=max(t[i-1][j],val[i-1]+t[i][j-wt[i-1]]);
            }
        }
    }
    return t[n][w];
}