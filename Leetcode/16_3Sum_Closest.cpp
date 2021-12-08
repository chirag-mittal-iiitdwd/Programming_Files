#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=INT_MAX,diff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i&&nums[i]==nums[i-1]){
                continue;
            }
            int l=i+1;
            int r=n-1;
            while(l<r){
                int currentSum=nums[i]+nums[l]+nums[r];
                if(abs(currentSum-target)<diff){
                    ans=currentSum;
                    diff=abs(currentSum-target);
                }
                if(currentSum>target){
                    r--;
                }
                else if(currentSum<target){
                    l++;
                }
                else{
                    return target;
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
        int target;
        cin>>target;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            nums[i]=x;
        }
        Solution obj;
        cout<<obj.threeSumClosest(nums,target)<<endl;
    }
}