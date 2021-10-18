#include<bits/stdc++.h>
using namespace std;

string LCSstring(string x,string y,int n,int m){
    int t[n+1][m+1];
    memset(t,-1,sizeof(t));
    for(int i=0;i<=n;i++){
        t[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        t[0][j]=0;
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
    cout<<t[n][m]<<endl;
    string revAns="";
    int i=n;
    int j=m;

    // Basically what happens while filling the table is that if our characters are equal than we add one to the previous value and write to next value
    // or else we take the maximum of both the values are store it to the next value
    // For printing we go in the reverse order
    // if the characters are eual than we we push it into answer or else we compare the the vales 
    // if t[i][j-1] is grater than other than we drease the column number
    // Or else we decrease the row
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            revAns.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    reverse(revAns.begin(),revAns.end());
    return revAns;
}

int main(){
    string x;
    string y;
    cin>>x>>y;
    cout<<LCSstring(x,y,x.length(),y.length());
}