#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        int i=0;
        int res=nums.size();
        for(auto &it:mp){
            if(it.first==val){
                res-=it.second;
            }
            else{
                for(int j=0;j<it.second;j++){
                nums[i]=it.first;i++;
            }
            }
        }
        return res;
    }
};