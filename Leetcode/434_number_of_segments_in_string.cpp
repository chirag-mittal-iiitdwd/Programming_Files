#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int ans=0;
        string cur={""};
        s+=" ";
        int n=s.length();

        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                cur+=s[i];
            }
            else{
                if(cur!=""){
                    ans++;
                    cur="";
                }
            }
        }
        return ans;
    }
};