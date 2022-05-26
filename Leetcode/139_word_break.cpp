#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();

        map<string,int>mp;
        for(auto&it:wordDict){
            mp[it]++;
        }

        string word="";
        for(int i=0;i<n;i++){
            word+=s[i];
            if(mp[word]!=0){
                word="";
            }
        }
        if(word!="" && mp[word]!=0){
            return true;
        }
        else if(word==""){
            return true;
        }
        else{
            return false;
        }
    }
};