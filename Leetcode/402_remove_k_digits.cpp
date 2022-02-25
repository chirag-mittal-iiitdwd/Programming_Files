#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;

        for(char&it:num){
            if(st.size() && st.top()>it && k){
                st.pop();
                k--;
            }
            if(st.size()!=0 || it!='0'){
                st.push(it);
            }
        }

        while(st.size()!=0 && k--){
            st.pop();
        }

        if(st.size()==0){
            return "0";
        }
        else{
            string ans="";
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    }
};