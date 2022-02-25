#include<bits/stdc++.h>
using namespace std;

class Solution
{
    bool isPresent(string &s1, string &s2)
    {
        int n1 = s1.length(), n2 = s2.length();
        int k=n2-n1+1;

        for(int i=0;i<k;i++){
            if(s2.substr(i,n1)==s1){
                return true;
            }
        }
        return false;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        sort(s1.begin(), s1.end()); // n1Logn1

        do
        {
            if (isPresent(s1, s2))
            {
                return true;
            } // n1!*(n2)
        } while (next_permutation(s1.begin(), s1.end()));
        return false;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        int k=n2-n1+1;
        unordered_map<char,int>mp;
        for(auto&it:s1){
            mp[it]++;
        }

        unordered_map<char,int>mp2;
        mp2=mp;

        for(int i=0;i<k;i++){
            string toMatch=s2.substr(i,n1);
            for(auto&it:toMatch){
                mp[it]--;
            }
            int j=0;
            for(;j<mp.size();j++){
                if(mp[j]!=0){
                    break;
                }
            }
            if(j==mp.size()){
                return true;
            }
            mp=mp2;
        }
        return false;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if(n1>n2){
            return false;
        }

        vector<int>s1_v(26,0),s2_v(26,0);
        int i=0;
        for(;i<n1;i++){
            s1_v[s1[i]-'a']++;
            s2_v[s2[i]-'a']++;
        }
        if(s1_v==s2_v){
            return true;
        }

        for(;i<n2;i++){
            s2_v[s2[i-n1]-'a']--;
            s2_v[s2[i]-'a']++;
            if(s2_v==s1_v){
                return true;
            }
        }
        return false;
    }
};