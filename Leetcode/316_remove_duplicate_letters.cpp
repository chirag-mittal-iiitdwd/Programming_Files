#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans="";
        int freq[26]={0};
        bool vis[26]={0};

        for(char&c:s){
            freq[c-'a']++;
        }

        for(char&c:s){
            freq[c-'a']--;
            if(vis[c]-'a'){
                continue;
            }

            while(c<ans.back() && freq[ans.back()-'a']){
                vis[ans.back()-'a']=false;
                ans.pop_back();
            }
            vis[c-'a']=true;
            ans+=c;
        }

        return ans;
    }
};