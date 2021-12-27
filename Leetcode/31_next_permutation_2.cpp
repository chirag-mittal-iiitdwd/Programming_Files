#include<bits/stdc++.h>
using namespace std;

class Solution {
    void recur(set<vector<int>>&s,int i,vector<int>nums){
        if(i>=nums.size()){
            s.insert(nums);
            return;
        }

        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            recur(s,i+1,nums);
            swap(nums[i],nums[j]);
        }
    }
public:
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        recur(s,0,nums);
        for(auto &it:s){
            ans.push_back(it);
        }
        sort(ans.begin(),ans.end());
        int pos=find(ans.begin(),ans.end(),nums)-ans.begin();
        if(pos==(ans.end()-ans.begin()-1)){
            // cout<<"exe"<<endl;
            nums=ans[0]; 
            return;
        }
        nums=ans[pos+1];
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution obj;
    obj.nextPermutation(nums);
    for(auto &it:nums){
        cout<<it<<" ";
    }
    cout<<endl;
}