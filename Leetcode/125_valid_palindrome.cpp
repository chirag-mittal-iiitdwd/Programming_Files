#include<bits/stdc++.h>
using namespace std;

class Solution {
    string formatted(string&s){
        string ans{""};
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isupper(s[i])){
                ans+=tolower(s[i]);
            }
            else if(islower(s[i])){
                ans+=s[i];
            }
            else if(isdigit(s[i])){
                ans+=s[i];
            }
            else{
                continue;
            }
        }
        return ans;
    }
public:
    bool isPalindrome(string s) {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        s=formatted(s);
        int l=0,r=s.length()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};


class Solution2{
    public:
    bool isPalindrome(string s){
        int left=0;
        int right=s.length()-1;
        while(left<right){
            char l=s[left];
            char r=s[right];
            if(isalnum(s[left]) && isalnum(s[right])){
                l=tolower(l);
                r=tolower(r);
                if(l!=r){
                    return false;
                }
                left++;
                right--;
            }
            else{
                if(!isalnum(l)){
                    left++;
                }
                if(!isalnum(r)){
                    right--;
                }
            }
        }
        return true;
    }
};