#include<bits/stdc++.h>
using namespace std;

class Solution {
    set<vector<int>>s;
    void helper(vector<int>nums,int target,vector<int>x,int i){
        if(target==0){
            s.insert(x);
            return;
        }
        else if(target<0){
            return;
        }
        else if(i==nums.size()){
            return;
        }
        else{
            x.push_back(nums[i]);
            helper(nums,target-nums[i],x,i+1);
            x.pop_back();
            helper(nums,target,x,i+1);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        for (int i = 0; i < n; i++){
            int more = target / candidates[i] - 1;
            for(int j = 0; j < more; j++){
                candidates.push_back(candidates[i]);
            }
        }
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,{},0);
        vector<vector<int>>ans;
        for(auto &it:s){
            ans.push_back(it);
        }
        return ans;
    }
};

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
        vector<vector<int>>ans=obj.combinationSum(nums,target);
        for(auto &it:ans){
            for(auto &i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}