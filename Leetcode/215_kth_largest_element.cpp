#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>q;
        for(auto&it:nums){
            q.push(it);
        }

        k--;
        int i=0;
        while(i<k){
            q.pop();
        }
        return q.top();
    }
};