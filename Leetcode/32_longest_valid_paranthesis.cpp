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

int main(){

}