#include<bits/stdc++.h>
using namespace std;

bool redundantParanthesis(string str){
    stack<char>st;
    for(int i=0;i<str.length();i++){
        if(str[i]!=')'){
            st.push(str[i]);
        }
        else{
            if(str[i]==')'){
                if(st.top()=='('){
                    return true;
                }
                while(!st.empty() && st.top()!='('){
                    st.pop();
                }
                st.pop();
            }
        }
    }
    if(st.empty()){
        return false;
    }
    return true;
}

int main(){
    string str;
    cin>>str;
    cout<<redundantParanthesis(str)<<endl;
}

// ((a+b))
//  stack = (