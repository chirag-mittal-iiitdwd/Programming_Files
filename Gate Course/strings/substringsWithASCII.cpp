#include<bits\stdc++.h>
using namespace std;

void substringWithASCII(string str,string ans){
    if(str.length()==0){
        cout<<ans<<" ";
        return;
    }
    char ch=str[0];
    int code=ch;
    string ros=str.substr(1);
    substringWithASCII(ros,ans);
    substringWithASCII(ros,ans+ch);
    substringWithASCII(ros,ans+to_string(code));
}

int main(){
    string str;
    cin>>str;
    substringWithASCII(str,"");
}