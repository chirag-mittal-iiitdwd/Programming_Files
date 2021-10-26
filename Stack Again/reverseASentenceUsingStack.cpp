#include<bits/stdc++.h>
using namespace std;

string reverseTheString(string str){
    string word;
    string ans;
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]!=' '){
            word=str[i]+word;
        }
        else{
            ans+=word;
            ans+=' ';
            word.clear();
        }
    }
    ans+=word;
    return ans;
}

string rreverseTheStringUsingStack(string str){
    stack<string>st;
    for(int i=0;i<str.length();i++){
        string word="";
        while(str[i]!=' '&&i<str.length()){
            word+=str[i];
            i++;
        }
        st.push(word);
    }

    string ans="";
    while(!st.empty()){
        ans+=st.top();
        ans+=' ';
        st.pop();
    }
    return ans;
}
int main(){
    string str;
    getline(cin,str);
    cout<<reverseTheString(str)<<endl;
    cout<<rreverseTheStringUsingStack(str)<<endl;

    // str=str+'a';
    // cout<<str<<endl;
}