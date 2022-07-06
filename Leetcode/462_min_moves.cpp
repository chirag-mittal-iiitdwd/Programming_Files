#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bool flag=false;
        int n=nums.size();

        if(n&1){
            flag=true;
        }
        int ans=INT_MAX;
        int idx=n/2,curAns=0;
        for(int i=0;i<n;i++){
            if(i==idx){
                continue;
            }
            curAns+=abs(nums[idx]-nums[i]);
        }
        ans=min(ans,curAns);
        curAns=0;

        idx++;
        if(flag){
            for(int i=0;i<n;i++){
                if(i==idx){
                    continue;
                }
                curAns+=abs(nums[idx]-nums[i]);
            }
            ans=min(ans,curAns);
        }

        return ans;
    }
};