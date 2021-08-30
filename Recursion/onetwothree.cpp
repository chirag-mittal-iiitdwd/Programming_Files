/*
    Time Complexity : O(lengthOfString)
    Space Complexity : O(lengthOfString) ---> Including call stack
*/

#include<bits/stdc++.h>
using namespace std;
void oneTwoThree(string s,int n){
    if(n<=-1){
        return;
    }
    oneTwoThree(s,n-1);
    if(s[n]=='1'){
        cout<<"One"<<" ";
    }
    if(s[n]=='2'){
        cout<<"Two"<<" ";
    }
    if(s[n]=='3'){
        cout<<"Three"<<" ";
    }
    if(s[n]=='4'){
        cout<<"Four"<<" ";
    }
    if(s[n]=='5'){
        cout<<"Five"<<" ";
    }
    if(s[n]=='6'){
        cout<<"Six"<<" ";
    }
    if(s[n]=='7'){
        cout<<"Seven"<<" ";
    }
    if(s[n]=='8'){
        cout<<"Eight"<<" ";
    }
    if(s[n]=='9'){
        cout<<"Nine"<<" ";
    }
    if(s[n]=='0'){
        cout<<"Zero"<<" ";
    }
}

int main(){
    string s="12345";
    int n=s.length();
    oneTwoThree(s,n);
    return 0;
}