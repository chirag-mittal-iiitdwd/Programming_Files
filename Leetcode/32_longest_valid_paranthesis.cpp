#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        int open=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }
            else{
//                 (()) --> Sample test case 1
//                 ()() --> Sample test case 2
//                 There is no other configuration of brackets
                if(open>0){
//                     Applicable in case of ()()
                    dp[i]=2+dp[i-1];
                    open--;
                    if(i-dp[i]>0){
//                         This part will be applicable in case of (())
                        dp[i]+=dp[i-dp[i]];
                    }
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()<2){
            return 0;
        }

        stack<int>st;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(!st.empty() && s[st.top()]=='('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }

        int maxLen=0;
        int endTerminal=s.length();

        while(!st.empty()){
            int startTerminal=st.top();
            st.pop();
            maxLen=max(maxLen,endTerminal-startTerminal-1);
            endTerminal=startTerminal;
        }

        return max(endTerminal,maxLen);
    }
};

int main(){

}