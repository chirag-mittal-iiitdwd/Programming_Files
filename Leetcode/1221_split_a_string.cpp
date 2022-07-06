#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int l=0,r=0,ans=0;
        for(auto&it:s){
            if(it=='L'){
                l++;
            }
            else{
                r++;
            }

            if(l==r){
                ans++;
            }
        }

        return ans;
    }
};