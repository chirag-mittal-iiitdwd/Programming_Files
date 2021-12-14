#include<bits/stdc++.h>
using namespace std;

class Solution {
    void helper(vector<int>&nums,int&target,pair<int,int>&p,int&n){
        sort(nums.begin(),nums.end());
        // for(auto it:nums){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        int l=0;
        int r=n-1;
        while(l<r){
            long long sum=(long long)nums[l]+nums[r];
            if(sum>1e9){
                r--;
            }
            else if(sum==target){
                // cout<<"SUM res : "<<sum<<endl;
                p.first=nums[l];
                p.second=nums[r];
                // cout<<p.first<<" "<<p.second<<endl;
                return;
            }
            else if(sum>target){
                // cout<<"SUM if : "<<sum<<endl;
                r--;
            }
            else{
                // cout<<"SUM else : "<<sum<<endl;
                l++;
            }
        }
    }
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>>mp;
        pair<int,int>p={INT_MAX,-1};
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        helper(nums,target,p,n);
        // cout<<p.first<<" "<<p.second<<endl;
        if(p.first!=INT_MAX && p.first==p.second){
            // cout<<"exeif"<<endl;
            ans.push_back(mp[p.first][0]);
            ans.push_back(mp[p.second][1]);
        }
        else if(p.first!=INT_MAX){
            // cout<<"exe"<<endl;
            ans.push_back(mp[p.first][0]);
            ans.push_back(mp[p.second][0]);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int,int> m;
//         vector<int> ret;
//         for(int i=0;i<nums.size();i++){
//             if(m.find(target-nums[i])!=m.end()){
//                 ret.push_back(i);
//                 ret.push_back(m[target-nums[i]]);
//                 return ret;
//             }
//             m[nums[i]] = i;
//         }
//         return ret;
//     }
// };

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,target;
        cin>>n>>target;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        Solution obj;
        for(auto &it:obj.twoSum(nums,target)){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

// 3 6
// 3 2 4
// 3 6
// 3 3