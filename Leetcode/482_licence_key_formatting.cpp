#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string str={""};
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z'){
                str+=toupper(s[i]);
            }
            else if(s[i]>='a' && s[i]<='z'){
                str+=tolower(s[i]);
            }
            else if(s[i]>='1' && s[i]<='9'){
                str+=s[i];
            }
            else{
                continue;
            }
        }

        n=str.length();
        int i=0;
        string ans={""};
        if((n%k)==0){
            ans+=str.substr(0,k);
            i=k;
        }
        else{
            ans+=str.substr(0,n%k);
            i=n%k;
        }

        while(i<n){
            ans+='-';
            ans+=str.substr(i,k);
            i+=k;
        }
        return ans;
    }
};