#include<bits/stdc++.h>
using namespace std;

class Solution {
    void twoSumMethod(vector<int>&nums,int&target,int&i,int&j,vector<int>&ans){
        if(i<j){
            int sum=nums[i]+nums[j];
            if(sum==target){
                ans.push_back(i);
                ans.push_back(j);
            }
            else if(sum>target){
                j=j-1;
                return twoSumMethod(nums,target,i,j,ans);
            }
            else{
                i=i+1;
                return twoSumMethod(nums,target,i,j,ans);
            }
        }
    }
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        vector<int>ans;
        twoSumMethod(nums,target,i,j,ans);
        return ans;
    }
};

int main(){
    int n,target;
    cin>>n>>target;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution obj;
    vector<int>ans=obj.twoSum(arr,target);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}