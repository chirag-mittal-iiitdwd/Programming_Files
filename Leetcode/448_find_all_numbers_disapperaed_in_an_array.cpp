#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int pos=abs(nums[i])-1;
            if(nums[pos]>0){
                nums[pos]=-nums[pos];
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};