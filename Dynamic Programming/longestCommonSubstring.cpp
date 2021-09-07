#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int longestCommonSubstring(string x,string y,int n,int m){
    int t[n+1][m+1];
    memset(t,-1,sizeof(t));
    for(int i=0;i<=n;i++){
        t[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        t[0][j]=0;
    }
    int result=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                t[i][j]=1+t[i-1][j-1];
                result=max(result,t[i][j]);
            }
            else{
                t[i][j]=0;
            }
        }
    }
    return result;
}

int main(){
    string x,y;
    cin>>x;
    cin>>y;
    cout<<x<<" "<<y<<endl;
    cout<<longestCommonSubstring(x,y,x.length(),y.length())<<endl;
    return 0;
}