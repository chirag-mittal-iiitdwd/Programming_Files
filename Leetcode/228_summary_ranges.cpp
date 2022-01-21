#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n=nums.size();
        if(n==1){
            ans.push_back(to_string(nums[0]));
            return ans;
        }

        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                r++;
            }
            else{
                if(l==r){
                    ans.push_back(to_string(nums[l]));
                }
                else{
                    ans.push_back(to_string(nums[l])+"->"+to_string(nums[r]));
                }
                l=r+1;
                r++;
            }
        }
        if(r<n){
            if(l==r){
                ans.push_back(to_string(nums[l]));
            }
            else{
                ans.push_back(to_string(nums[l])+"->"+to_string(nums[r]));
            }
        }
        return ans;
    }
};