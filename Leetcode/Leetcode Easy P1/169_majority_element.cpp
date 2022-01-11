#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cur=nums[0];
        int cnt=1;
        for(int i=1;i<n;i++){
            if(cur==nums[i]){
                cnt++;
            }
            else{
                cnt--;
                if(cnt==0){
                    cur=nums[i];
                    cnt=1;
                }
            }
        }
        return cur;
    }
};
