#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());

        int i=0,j=0,n=word1.size(),m=word2.size(),ans=0;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                i++;
                j++;
            }
            else if(word1[i]<word2[j]){
                i++;
                ans++;
            }
            else{
                j++;
                ans++;
            }
        }

        while(i<n){
            i++;
            ans++;
        }

        while(j<m){
            j++;
            ans++;
        }

        return ans;
    }
};

class Solution {
int lowestCommonSubsequenceTopDown(string x,string y,int n,int m){
    int t[n+1][m+1];
    memset(t,-1,sizeof(t));
    for(int i=0;i<n;i++){
        t[i][0]=0;
    }
    for(int i=0;i<m;i++){
        t[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
        }
    }
    return t[n][m];
}
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        int lcsVal=lowestCommonSubsequenceTopDown(word1,word2,n,m);
        return (n+m-(2*(lcsVal)));
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        int t[m+1][n+1];
        for(int i=0;i<m+1;i++)     //initializing matrix at i=changing and j=0
            t[i][0]=0;          
        for(int j=0;j<n+1;j++)     //initializing matrix at i=0 and j=changing
            t[0][j]=0;            
        for(int i=1;i<m+1;i++) {       //Filling the remaining grids of matrix
            for(int j=1;j<n+1;j++) {
                if(word1[i-1]==word2[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
        }
        int del=m-t[m][n];//first delete element from string 'word1' which is Not present in string 'word2'
        int ins=n-t[m][n];//Then insert elements which are required in string 'word2'
        return del+ins;
    }
};