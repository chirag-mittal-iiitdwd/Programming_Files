#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        for(auto &it:{2,3,5}){
            while((n%it)==0){
                n/=it;
            }
        }
        return n>1;
    }
};