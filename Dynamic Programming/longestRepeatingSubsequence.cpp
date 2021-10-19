#include<bits/stdc++.h>
using namespace std;

int longestRepeatingSubsequence(string x,string y,int n,int m){
    int t[n+1][m+1];
    for(int i=0;i<=n;i++){
        t[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        t[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1] && i!=j){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    // string ans;
    // int i=n;
    // int j=m;
    // while(i>0 && j>0){
        
    // }

    return t[n][m];
}
int main(){
    string x,y;
    cin>>x;
    y=x;
    reverse(x.begin(),x.end());
    cout<<longestRepeatingSubsequence(x,y,x.length(),y.length())<<endl;
}