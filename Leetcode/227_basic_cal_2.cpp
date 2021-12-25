#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        char sign='+';
        int n=s.length();

        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                int val=0;
                while(i<n && isdigit(s[i])){
                    val=((val*10)+(s[i]-'0'));
                    i++;
                }
                i--;
                if(sign=='+'){
                    st.push(val);
                }
                else if(sign=='-'){
                    st.push(-val);
                }
                else if(sign=='*'){
                    int f=st.top();
                    st.pop();
                    int ans=f*val;
                    st.push(ans);
                }
                else if(sign=='/'){
                    int f=st.top();
                    st.pop();
                    int ans=f/val;
                    st.push(ans);
                }
            }
            else if(s[i]!=' '){
                sign=s[i];
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};