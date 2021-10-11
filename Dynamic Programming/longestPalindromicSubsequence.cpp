#include<bits\stdc++.h>
using namespace std;

/*  
    Take out palindromic subsequence out of all subsequences than find longest

    Approach : Take the current string and reverse it and strore it int another string
    Now apply LCS to both these strings 
    this will return the longest palindromic subsequence because one string is reverse of other
    therefor the answer will be LPS
*/

int longestPalindromicSubsequence(string x,int n){
    string y=x;
    reverse(x.begin(),x.end());
    int t[n+1][n+1];
    for(int i=0;i<=n;i++){
        t[i][0]=0;
        t[0][i]=0;
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
    return t[n][n];
}

int main(){
    string x;
    cin>>x;
    cout<<longestPalindromicSubsequence(x,x.length())<<endl;
}