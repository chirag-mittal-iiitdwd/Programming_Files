#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>nums;
        for(auto&it:ops){
            if(it=="+"){
                int sum=nums[nums.size()-1]+nums[nums.size()-2];
                nums.push_back(sum);
            }
            else if(it=="D"){
                nums.push_back(nums[nums.size()-1]*2);
            }
            else if(it=="C"){
                nums.pop_back();
            }
            else{
                nums.push_back(stoi(it));
            }
        }

        int sum=0;
        for(auto&it:nums){
            sum+=it;
        }
        return sum;
    }
};