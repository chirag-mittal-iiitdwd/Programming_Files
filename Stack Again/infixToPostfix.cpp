/*
    if operand
        print
    if '('
        push to stack
    if ')'
        pop and print until '(' is found
    if operator
        pop from stack and print until an opeator with less precedance is found
        after that push current opeartor
*/

#include<bits/stdc++.h>
using namespace std;

int precedance(char ch){
    if(ch=='^'){
        return 4;
    }
    else if(ch == '*' || ch == '/'){
        return 3;
    }
    else if(ch == '+' || ch == '-'){
        return 2;
    }
    else{
        return 1;
    }
}

string infixToPostfix(string str){
    stack<char>st;
    string ans="";
    for(int i=0;i<str.length();i++){
        if((str[i]>='a' && str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
            ans+=str[i];
        }
        else if(str[i]=='('){
            st.push(str[i]);
        }
        else if(str[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            int currentPrec=precedance(str[i]);
            while(!st.empty() && precedance(st.top())>currentPrec){
                ans+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

int main(){
    string str;
    cin>>str;
    cout<<infixToPostfix(str)<<endl;
    // (a-b/c)*(a/k-l) 
    // abc/-ak/l-*
}