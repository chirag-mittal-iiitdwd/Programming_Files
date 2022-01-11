#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i-1]==nums[i]){
                continue;
            }
            int start=i;
            int end=n-1;
            while(start<end){
                int sum=nums[start]+nums[end];
                if(sum==target){
                    if(nums[start]==nums[end]){
                        return {mp[nums[start]][0],mp[nums[end]][1]};
                    }
                    return {mp[nums[start]][0],mp[nums[end]][0]};
                }
                else if(sum<target){
                    start++;
                }
                else{
                    end--;
                }
            }
        }
        return {};
    }
};

class Solution2{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        sort(nums.begin(),nums.end());
        int start=0;
        int end=n-1;
        while(start<end){
            int sum=nums[start]+nums[end];
            if(sum==target){
                if(nums[start]==nums[end]){
                    return {mp[nums[start]][0],mp[nums[end]][1]};
                }
                return {mp[nums[start]][0],mp[nums[end]][0]};
            }
            else if(sum<target){
                while(start<n && nums[start]==nums[start+1]){
                    start++;
                }
                start++;
            }
            else{
                while(end>=0 && nums[end]==nums[end-1]){
                    end--;
                }
                end--;
            }
        }
        return {};
    }
};

class Solution3{
    public:
    vector<int>twoSum(vector<int>&nums,int target){
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(target-nums[i])!=mp.end()){
                return {i,mp[target-nums[i]]};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}