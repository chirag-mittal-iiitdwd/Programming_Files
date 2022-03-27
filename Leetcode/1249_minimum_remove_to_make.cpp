#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        int n=s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    s[i]='*';
                }
            }
        }

        while(!st.empty()){
            s[st.top()]='*';
        }

        string ans;
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                ans+=s[i];
            }
        }
        return ans;   
    }
};