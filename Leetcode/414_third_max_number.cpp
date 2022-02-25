#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());

        auto it=s.end();
        if(s.size()<3){
            advance(it,-1);
            return *it;
        }
        advance(it,-3);
        return *it;
    }
};