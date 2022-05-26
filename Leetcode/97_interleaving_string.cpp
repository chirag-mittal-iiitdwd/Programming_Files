#include<bits/stdc++.h>
using namespace std;

// Changing i,j
class Solution {
public:
    bool answ(string s1,int i,string s2,int j,string ans,string s3)
    {
        if(ans==s3 and i==s1.length() and j==s2.length())
            return true;
        
        bool a=false;
        
        if(i<s1.length())
            a|=answ(s1,i+1,s2,j,ans+s1[i],s3);
        
        if(j<s2.length())
            a|=answ(s1,i,s2,j+1,ans+s2[j],s3);
        
        return a;
    }
    
    bool isInterleave(string s1, string s2, string s3)
    {
        return answ(s1,0,s2,0,"",s3);
    }
};

class Solution {
    int dp[101][101][201];
    bool helper(int i,int j,int len,string s1,string s2,string s3){
        if(i==s1.size()){
            while(j<s2.size()){
                if(s3[len]!=s2[j]){
                    return false;
                }
                len++;
                j++;
            }

            return true;
        }

        if(j==s2.size()){
            while(i<s1.size()){
                if(s1[i]!=s3[len]){
                    return false;
                }
                len++;
                i++;
            }

            return true;
        }

        if(dp[i][j][len]!=-1){
            return dp[i][j][len];
        }

        bool v1=false,v2=false;
        if(s1[i]==s3[len]){
            v1=helper(i+1,j,len+1,s1,s2,s3);
        }
        if(s2[j]==s3[len]){
            v2=helper(i,j+1,len+1,s1,s2,s3);
        }

        return dp[i][j][len]=v1|v2;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,0,s1,s2,s3);
    }
};