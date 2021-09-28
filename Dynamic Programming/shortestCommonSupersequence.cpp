/*
    Supersequence is the sequence which has both the subsequences
    The elements which will be repeating if we simpliy merge the elements are the LCS elements

    In order to find minimum length we need to stutract LCS length from the sum of length of both strings
*/

#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(string x,string y,int n,int m){
    int t[n+1][m+1];
    memset(t,-1,sizeof(t));
    for(int i=0;i<=n;i++){
        t[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        t[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return ((n+m)-t[n][m]);
}

int main(){
    string x="AGGTAB";
    string y="GXTXAYB";
    cout<<shortestCommonSupersequence(x,y,x.length(),y.length());
}