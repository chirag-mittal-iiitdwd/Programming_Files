#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        bool flag=true;
        
        int lastReached=n-1;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]<lastReached){
                flag=false;
            }
            else{
                flag=true;
                lastReached=i;
            }
        }
        return flag;
    }
};