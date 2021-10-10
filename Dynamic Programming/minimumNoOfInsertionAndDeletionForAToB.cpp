#include<bits/stdc++.h>
using namespace std;
/*
    Whenever we are given with two strings and it is saying to 
    optimize anything thatn it is sure that it is a question of LCS

    and this question is asking for an integer output and in LCS also we are required to output 
    an integer

    A = { h , e , a , p }
    B = { p , e , a }
    e a is the LCS of B, convert heap to ea than convert ea to pea

    Number of deletions from string A = length of string A { h, e, a, p} - The length of LCS { e, a}
    Number of insertions to A = Length of B { p, e, a} - The length of LCS { e, a}
*/

int minimumNumberOfInsertionAndDeletion(string x,string y,int n,int m){
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
    return ((n+m)-2*(t[n][m]));
}

int main(){
    string x,y;
    cin>>x>>y;
    cout<<minimumNumberOfInsertionAndDeletion(x,y,x.length(),y.length())<<endl;
}