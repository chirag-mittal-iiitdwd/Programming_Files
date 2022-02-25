#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto&it:strs){
            string s=it;
            sort(s.begin(),s.end());
            mp[s].push_back(it);
        }

        vector<vector<string>>ans;
        for(auto&it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

class Solution {
    string countingSort(string str){
        string ans={""};
        vector<int>v(26,0);
        for(auto&it:str){
            v[it-'a']++;
        }

        for(int i=0;i<26;i++){
            for(int j=0;j<v[i];j++){
                ans+=((char)(i+'a'));
            }
        }
        return ans;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto&it:strs){
            mp[countingSort(str)].push_back(it);
        }
        vector<vector<string>>ans;
        for(auto&it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};