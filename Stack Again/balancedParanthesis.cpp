#include<bits/stdc++.h>
using namespace std;

bool balancedParantheses(string str){
    stack<char>st;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
            st.push(str[i]);
        }
        else if(str[i]==')'){
            if(st.top()!='('){
                return false;
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else if(str[i]==']'){
            if(st.top()!='['){
                return false;
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            if(st.top()!='{'){
                return false;
            }
            if(!st.empty()){
                st.pop();
            }
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}

int main(){
    string str;
    cin>>str;
    cout<<balancedParantheses(str)<<endl;
}