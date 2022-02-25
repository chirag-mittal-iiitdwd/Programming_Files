#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ns=s.length(),nt=t.length(),i=0,j=0;

        while(i<ns && j<nt){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }

        return i==ns;
    }
};w