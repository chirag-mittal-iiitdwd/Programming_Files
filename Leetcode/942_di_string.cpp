#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> diStringMatch(string s) {
        int dec=0;
        for(auto&it:s){
            if(it=='D'){
                dec++;
            }
        }

        int inc=dec;
        vector<int>ans{dec};
        for(auto&it:s){
            if(it=='D'){
                ans.push_back(--dec);
            }
            else{
                ans.push_back(++inc);
            }
        }

        return ans;
    }
};