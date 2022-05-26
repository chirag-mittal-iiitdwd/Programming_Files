#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int>mp;

        int n=s.length();
        if(n<10){
            return {};
        }

        string dna="";
        int k=10;
        for(int i=0;i<k;i++){
            dna+=s[i];
        }
        mp[dna]++;

        for(int i=1;i<n-k+1;i++){
            dna=dna.substr(1);
            dna+=s[i+k-1];
            mp[dna]++;
        }

        vector<string>v;
        for(auto&it:mp){
            if(it.second>1){
                v.push_back(it.first);
            }
        }
        return v;
    }
};