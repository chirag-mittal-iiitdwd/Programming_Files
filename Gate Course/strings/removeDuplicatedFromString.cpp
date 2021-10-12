#include<bits/stdc++.h>
using namespace std;

void removeDuplicateFromString(string str){
    if(str.length()==0){
        return;
    }
    char current=str[0];
    string x=str.substr(1);
    if(x[0]==current){
        removeDuplicateFromString(x);
    }
    else{
        cout<<current;
        removeDuplicateFromString(x);
    }
}

string removeDup(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string ans=removeDup(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
    return (ch+ans);
}

string removeDuplicateIter(string str){
    int n=str.length();
    if(n==0){
        return "";
    }
    else if(n==1){
        return str;
    }
    else{
        string ans="";
        char current=str[0];
        for(int i=1;i<n;i++){
            if(current!=str[i]){
                ans+=current;
                current=str[i];
            }
        }
        ans+=current;
        return ans;
    }
}

int main(){
    cout<<removeDup("aaaaaabbbbbcccccddddrrrrrfffff")<<endl;
    cout<<removeDuplicateIter("aaaaaabbbbbcccccddddrrrrrfffff")<<endl;
    removeDuplicateFromString("aaaaaabbbbbcccccddddrrrrrfffff");
}