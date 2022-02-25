#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPalindrome(string str){
        int n=str.length();
        int i=0,j=n-1;
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        if(isPalindrome(s)){
            return true;
        }

        int n=s.length();
        for(int i=0;i<n;i++){
            string str=s.substr(0,i)+s.substr(i+1);
            if(isPalindrome(str)){
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,r=s.length()-1;

        while(l<=r){
            if(s[l]==s[r]){
                r--;
                l++;
            }
            else{
                int f=l+1,e=r;
                while(s[f]==s[e] && f<=e){
                    f++;
                    e--;
                }
                if(f>e){
                    return true;
                }

                f=l,e=r-1;
                while(s[f]==s[e] && f<=e){
                    f++;
                    e--;
                }
                if(f>e){
                    return true;
                }
                return false;
            }
        }
        return true;
    }
};