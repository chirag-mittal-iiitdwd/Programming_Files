#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getval(char c){
        if(c == 'I') return 1;
        if(c == 'V') return 5;
        if(c == 'X') return 10;
        if(c== 'L') return 50;
        if(c == 'C') return 100;
        if(c == 'D') return 500;
        return 1000;
    }
    
    int romanToInt(string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
            int v1 = getval(s[i]);
            if(i+1 < s.length()){
                int v2 = getval(s[i+1]);
                if(v1>=v2){
                    ans+=v1;
                }else{
                    ans= ans+v2-v1;i++;
                }
            }else{
               ans+=v1; 
            }
        }
        return ans;
    }
};