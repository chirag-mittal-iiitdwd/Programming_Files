#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        unordered_map<char,int>mp;
        for(auto&it:magazine){
            mp[it]++;
        }
        for(auto&it:ransomNote){
            if(mp[it]>0){
                mp[it]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
