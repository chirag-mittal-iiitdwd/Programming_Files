/*
    Basically reverse the given string
    and then either change ( to ) and ) to ( or in the programm change ( to ) and ) to (
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

string infixToPrefix(string str){
    reverse(str.begin(),str.end());
    stack<char>st;
    string ans="";
    for(int i=0;i<str.length();i++){
        if((str[i]>='a' && str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
            ans+=str[i];
        }
        else if(str[i]==')'){
            st.push(str[i]);
        }
        else if(str[i]=='('){
            while(!st.empty() && st.top()!=')'){
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
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string str;
    cin>>str;
    cout<<infixToPrefix(str)<<endl;
    // (a-b/c)*(a/k-l) 
    // *-a/bc-/akl
}