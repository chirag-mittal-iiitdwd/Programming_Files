#include<bits/stdc++.h>
using namespace std;

string minimumInsertionToMakePalindrome(string x,int n){
    string y=x;
    reverse(x.begin(),x.end());
    int t[n+1][n+1];
    for(int i=0;i<n;i++){
        t[i][0]=0;
        t[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                t[i][j]=t[i-1][j-1]+1;
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    
    string palindrome;
    int i=n;
    int j=n;
    while(j>0 && i>0){
        if(x[i-1]==y[j-1]){
            palindrome.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            palindrome.push_back(x[i-1]);
            palindrome.push_back(y[j-1]);
            i--;
            j--;
        }
    }
    return palindrome;
}

int main(){
    string x;
    cin>>x;
    cout<<minimumInsertionToMakePalindrome(x,x.length())<<endl;
}