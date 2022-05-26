#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool helper(string&s,string&p,int i,int j,unordered_map<char,vector<int>>&mp){
        if(i==0 && j==0){
            return true;
        }
        if(j==0 || (i==0 && p[j]!='*')){
            return false;
        }
        if((i==0 && p[j]=='*')||(j==1 && )){
            return helper(s,p,i,j-1,mp);
        }
        if(p[j]==s[i] || p[j]=='?'){
            return helper(s,p,i-1,j-1,mp);
        }
        if(p[j]=='*'){
            char toFind=p[j-1];
            if(mp[toFind].size()==0){
                return false;
            }
            bool result=false;
            for(int x=0;x<mp[toFind].size() && x<=i;x++){
                result=helper(s,p,x-1,j-1,mp);
                if(result){
                    return true;
                }
            }
            return helper(s,p,i,j-1,mp);
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }
        return helper(s,p,s.length()-1,p.length()-1,mp);
    }
};

class Solution {
    bool helper(string&s,string&p,int i,int j){
        if(i==s.length() && j==p.length()){
            return true;
        }

        if(i==s.length()){
            for(int idx=j;idx<p.length();idx++){
                if(p[idx]!='*'){
                    return false;
                }
                return true;
            }
        }

        if(j==p.length() && i!=s.length()){
            return false;
        }

        bool ans=false;
        if(p[j]=='?'){
            if(helper(s,p,i+1,j+1)){
                ans=true;
            }
        }
        else if(p[j]=='*'){
            if(helper(s,p,i,j+1)){
                ans=true;
            }
            if(helper(s,p,i+1,j+1)){
                ans=true;
            }
            if(helper(s,p,i+1,j)){
                ans=true;
            }
        }
        else{
            if(s[i]==p[j] && helper(s,p,i+1,j+1)){
                ans=true;
            }
        }
        return ans;
    }
public:
    bool isMatch(string s, string p) {
        return helper(s,p,0,0);
    }
};