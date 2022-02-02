#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isMatch(unordered_map<char,int>mpp,unordered_map<char,int>mps){
        for(auto&it:mpp){
            if(mps[it.first]!=it.second){
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int np=p.length(),ns=s.length(),k=(ns-np+1);

        if(k<=0){
            return {};
        }
        else{
            vector<int>ans;
            unordered_map<char,int>mps;
            unordered_map<char,int>mpp;
            for(auto&it:p){
                mpp[it]++;
            }

            for(int i=0;i<np;i++){
                mps[s[i]]++;
            }
            if(isMatch(mpp,mps)){
                ans.push_back(0);
            }
            for(int i=1;i<k;i++){
                mps[s[i-1]]--;
                mps[s[np-1+i]]++;
                if(isMatch(mpp,mps)){
                    ans.push_back(i);
                }
            }
            return ans;
        }
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l1=s.length(),l2=p.length(),k=(l1-l2+1);
        vector<int>ans;

        if(k<=0){
            return ans;
        }
        vector<int>pattern(26,0);
        vector<int>str(26,0);
        for(int i=0;i<l2;i++){
            pattern[p[i]-'a']++;
            str[s[i]-'a']++;
        }
        if(pattern==str){
            ans.push_back(0);
        }

        int l=1,r=l2;
        while(r<l1){
            str[s[l-1]-'a']--;
            str[s[r]-'a']++;
            if(pattern==str){
                ans.push_back(l);
            }
            l++;
            r++;
        }
        return ans;
    }
};