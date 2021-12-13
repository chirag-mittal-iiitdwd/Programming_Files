#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int l=j+1;
                int r=n-1;
                while(l<r){
                    long long sum=(long long)nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum>1e9) r--;
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        while(r>1 && nums[r]==nums[r-1]){
                            r--;
                        }
                        while(l<n && nums[l]==nums[l-1]){
                            l++;
                        }
                    }
                    else if(sum>target){
                        r--;
                    }
                    else{
                        l++;
                    }
                }
                
            }
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
        vector<vector<int>>ans=obj.fourSum(nums,target);
        for(auto &it:ans){
            for(auto &i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}