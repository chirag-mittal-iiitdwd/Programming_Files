#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int>mp;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        for(int i=0;i<n;i++){
            if(mp[t[i]]==0){
                return false;
            }
            mp[t[i]]--;
        }
        for(auto &it:mp){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
};