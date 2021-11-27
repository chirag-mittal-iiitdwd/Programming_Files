#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int lengthOfLongestSubstring(string s){
        map<char,int>mp;
        int mx=INT_MIN;
        int cur=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(mp[s[i]]==0){
                cur++;
            }
            else{
                mx=max(mx,cur);
                mp[]
            }
        }
    }
};