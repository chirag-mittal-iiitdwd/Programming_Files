#include<bits/stdc++.h>
using namespace std;

class palindromePart{
    vector<vector<string>>ans;
    bool isPalindrome(string str,int i,int j){
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int t[100][100];
    int palindromePartitioning(string str,int i,int j){
        if(i==j || isPalindrome(str,i,j)){
            // ans.push_back(str.substr(i,j-i));
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        t[i][j]=INT_MAX;
        for(int k=i;k<j;k++){
            t[i][j]=min(t[i][j],palindromePartitioning(str,i,k)+palindromePartitioning(str,k+1,j)+1);
        }
        return t[i][j];
    }
    vector<vector<string>> partition(string s) {

    }
};

class Solution {
    public:
    bool isPal(string &s){
        for(int i=0;i<s.length()/2;i++){
            if(s[i]!=s[s.length()-i-1]){
                return false;
            }
        }
        return true;
    }

    void helper(string &s,int index,vector<string>&curr,vector<vector<string>>&ans){
        if(index==s.length()){
            ans.push_back(curr);
            return;
        }
        string tmp="";
        for(int i=index;i<s.length();i++){
            tmp.push_back(s[i]);
            if(isPal(tmp)){
                curr.push_back(tmp);
                helper(s,i+1,curr,ans);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s){
        vector<string>curr;
        vector<vector<string>>ans;
        helper(s,0,curr,ans);
        return ans;
    }
};