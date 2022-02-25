#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        map<int,char>mp1;
        for(auto&it:s){
            mp[it]++;
        }

        int ans=0,mx=0;
        bool flag=false;
        for(auto&it:mp){
            if(it.second%2==0){
                ans+=it.second;
            }
            else{
                flag=true;
                ans+=(it.second-1);
            }
        }
        if(flag){
            ans++;
        }
        return ans;
    }
};