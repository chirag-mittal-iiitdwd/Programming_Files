#include<bits/stdc++.h>
using namespace std;

void print_all_subsequence(string str,string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=str[0];
    print_all_subsequence(str.substr(1),ans);
    print_all_subsequence(str.substr(1),ans+ch);
}

int main(){
    string str;
    cin>>str;
    print_all_subsequence(str,"");
}