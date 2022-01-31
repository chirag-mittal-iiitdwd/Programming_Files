#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        unordered_set<int> t;
        for (int i = 31; i >= 0; i--){
            mask |= (1 << i);
            t.clear();
            for (int n: nums){
                t.insert(mask & n);
            } 
            int candidate = max | (1<<i);
            for (int prefix : t){
                if (t.find(prefix ^ candidate) != t.end()){
                    max = candidate;
                    break;
                }
                
            }
        }
        return max;
    }
};
