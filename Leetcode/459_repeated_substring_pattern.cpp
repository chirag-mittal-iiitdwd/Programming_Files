#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        for(int i=1;i<n;i++){
            string sub=s.substr(0,i);
            if((n%i)==0){
                int m=sub.length();
                int j=0;
                for(;j<n;j+=m){
                    if(s.substr(j,m)!=sub){
                        break;
                    }
                }
                if(j==n){
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string original=s;
        int n=s.length();
        s=s+s;
        string tocmp=s.substr(1,(2*n)-2);
        return tocmp.find(original)!=string::npos;
    }
};
