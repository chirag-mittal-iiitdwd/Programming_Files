#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.length()==0){
            return 0;
        }
        string str=s;
        reverse(s.begin(),s.end());

        if(s==str){
            return 1;
        }
        return 2;
    }
};