#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for(char&it:s){
            if(it=='('){
                st.push(0);
            }
            else{
                int temp=st.top();
                st.pop();
                int val=0;
                if(temp>0){
                    val=temp*2;
                }
                else{
                    val=1;
                }
                st.top()+=val;
            }
        }

        return st.top();
    }
};