/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int prec(char ch){
    if(ch=='^'){
        return 4;
    }
    else if(ch=='*' || ch=='/'){
        return 3;
    }
    else if(ch=='+' || ch=='-'){
        return 2;
    }
    else{
        return 1;
    }
}

string infixToPostfix(string str){
    stack<char>st;
    string ans="";
    int n=str.length();
    for(int i=0;i<n;i++){
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
            int currentPrec=prec(str[i]);
            while(!st.empty()&&prec(st.top())>currentPrec){
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        cout<<infixToPostfix(str)<<endl;
    }
    return 0;
}