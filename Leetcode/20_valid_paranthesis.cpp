#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                // cout<<"exe"<<endl;
                if(s[i]==')'){
                    if(st.empty()||st.top()!='('){
                        return false;
                    }
                    if(!st.empty()){
                        st.pop();
                    }
                }
                else if(s[i]==']'){
                    if(st.empty()||st.top()!='['){
                        return false;
                    }
                    if(!st.empty()){
                        st.pop();
                    }
                }
                else{
                    if(st.empty()||st.top()!='{'){
                        return false;
                    }
                    if(!st.empty()){
                        st.pop();
                    }
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution obj;
        cout<<obj.isValid(str)<<endl;
    }
}