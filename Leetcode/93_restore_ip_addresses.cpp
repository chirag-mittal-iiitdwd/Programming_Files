#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(string str){
        if(str.length()>3){
            return false;
        }
        if(str[0]=='0' && str.length()>1){
            return false;
        }
        int num=stoi(str);
        return num<=255;
    }
    void helper(vector<string>&ans,string s,int idx,string temp,int parts){
        if(idx>=s.length() || parts>=4){
            if(idx==s.length() && parts==4){
                temp.pop_back();
                ans.push_back(temp);
            }
            return;
        }

        if(idx+1<=s.length()){
            helper(ans,s,idx+1,temp+s[idx]+".",parts+1);
        }
        if(idx+2<=s.length() && isValid(s.substr(idx,2))){
            helper(ans,s,idx+2,temp+s.substr(idx,2)+".",parts+1);
        }
        if(idx+3<=s.length() && isValid(s.substr(idx,3))){
            helper(ans,s,idx+3,temp+s.substr(idx,3)+".",parts+1);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        helper(ans,s,0,"",0);
        return ans;
    }
};

class Solution {
    bool isValid(string&str){
        if(str.length()>3){
            return false;
        }
        if(str[0]=='0' && str.length()>1){
            return false;
        }
        int num=stoi(str);
        return num<=255;
    }
    void helper(vector<string>&ans,string&s){
        for(int i=1;i<=3 && i<s.length();i++){
            string first=s.substr(0,i);
            if(isValid(first)){
                for(int j=1;j<=3 && (i+j)<s.length();j++){
                    string second=s.substr(i,j);
                    if(isValid(second)){
                        for(int k=1;k<=3 && (i+j+k)<s.length();k++){
                            string third=s.substr(i+j,k);
                            string fourth=s.substr(i+j+k);
                            if(isValid(third) && isValid(fourth)){
                                ans.push_back(first+"."+second+'.'+third+"."+fourth);
                            }
                        }
                    }
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        helper(ans,s);
        return ans;
    }
};