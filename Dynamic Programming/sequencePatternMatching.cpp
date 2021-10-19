/*
    we have to find if subsequence a is present in b
    for this we will first find lcs of both and than compare the lcs with string a
*/

#include<bits/stdc++.h>
using namespace std;

bool sequencePatternMatching(string a,string b,int n,int m){
    int t[n+1][m+1];
    for(int i=0;i<=n;i++){
        t[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        t[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    // This way can also be used but we can just soimply compare the length of lcs and length of a
    // string lcs;
    // int i=n;
    // int j=m;
    // while(i>0 && j>0){
    //     if(a[i-1]==b[j-1]){
    //         lcs.push_back(a[i-1]);
    //         i--;
    //         j--;
    //     }
    //     else{
    //         if(t[i-1][j]>t[i][j-1]){
    //             i--;
    //         }
    //         else{
    //             j--;
    //         }
    //     }
    // }

    // reverse(lcs.begin(),lcs.end());
    // if(lcs==a){
    //     return true;
    // }
    // else{
    //     return false;
    // }
    
    if(t[n][m]==a.length()){
        return true;
    }
    return false;
}

int main(){
    string a,b;
    cin>>a>>b;
    cout<<sequencePatternMatching(a,b,a.length(),b.length())<<endl;
}