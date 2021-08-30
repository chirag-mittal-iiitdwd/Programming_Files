#include<iostream>
#include<stack>
using namespace std;

bool balancedPara(string s){
    stack<char> st;
    bool ans=true;
    int size=s.length();
    for(int i=0;i<size;i++){
        stack<char> st;
        // if(s[i]!='(' || s[i]!='{' || s[i]!='[' || s[i]!=')' || s[i]!='}' || s[i]!=']'){
        //     ans=false;
        //     break;
        // }
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else if(!st.empty() && s[i]=='}'){
            if(st.top()=='{'){
                st.pop();
            }
            else{
                ans=false;
                break;
            }
        }
        else if(!st.empty() && s[i]==')'){
            if(st.top()=='('){
                st.pop();
            }
            else{
                ans=false;
                break;
            }
        }
        else if(!st.empty() && s[i]==']'){
            if(st.top()=='['){
                st.pop();
            }
            else{
                ans=false;
                break;
            }
        }
    }
    if(!st.empty()){
        ans=false;
    }
    return ans;
}

int main(){
    cout<<balancedPara("([afzzdv{}])")<<endl;
}