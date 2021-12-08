#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans={};
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i&&nums[i]==nums[i-1]){
                continue;
            }
            int l=i+1;
            int r=n-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]>0){
                    r--;
                }
                else if(nums[i]+nums[l]+nums[r]<0){
                    l++;
                }
                else{
                    ans.push_back({nums[i],nums[l],nums[r]});
                    int le=nums[l],re=nums[r];
                    while(l<r&&nums[l]==le){
                        l++;
                    }
                    while(l<r&&nums[r]==re){
                        r--;
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
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            nums[i]=x;
        }
        Solution obj;
        vector<vector<int>>ans=obj.threeSum(nums);
        for(auto &it:ans){
            for(auto &i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}