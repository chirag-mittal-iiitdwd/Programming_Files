#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int oneCnt=0,zeroCnt=0;
        for(auto&it:nums){
            if(it==1){
                oneCnt++;
            }
            else{
                zeroCnt++;
            }
        }
        if(oneCnt==0 || zeroCnt==0){
            return 0;
        }
        int l=0,r=nums.size()-1;
        while(l<r){
            if(oneCnt==zeroCnt){
                return oneCnt*2;
            }
            if(oneCnt<zeroCnt){
                if(nums[l]==0){
                    l++;
                    zeroCnt--;
                }
                else if(nums[r]==0){
                    r--;
                    zeroCnt--;
                }
                else{
                    l++;
                    oneCnt--;
                }
            }
            else{
                if(nums[l]==1){
                    l++;
                    oneCnt--;
                }
                else if(nums[r]==1){
                    r--;
                    oneCnt--;
                }
                else{
                    l++;
                    zeroCnt--;
                }
            }
        }
        return 0;
    }
};