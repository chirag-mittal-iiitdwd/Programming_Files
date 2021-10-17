#include<bits/stdc++.h>
using namespace std;

int minimumDeletionsForPalindrome(string x){
    int n=x.length();
    string y=x;
    reverse(x.begin(),x.end());
    int t[n+1][n+1];
    for(int i=0;i<n;i++){
        t[0][i]=0;
        t[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return n-t[n][n];
}

int main(){
    string str;
    cin>>str;
    cout<<minimumDeletionsForPalindrome(str)<<endl;
}