#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int>productExceptSelf(vector<int>&nums){
        int n=nums.size();
        int product=1;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            product*=nums[i];
            ans[i]=product;
            // product*=nums[i];
        }
        product=1;
        for(int i=n-1;i>0;i--){
            ans[i]=ans[i-1]*product;
            product*=nums[i];
        }
        ans[0]=product;
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         int leftProduct{1};
//         int rightProduct{1};
//         vector<int> ans(n, 1);
//         for (int i = 0; i < n; i++) {
//             ans[i] = ans[i] * leftProduct;
//             leftProduct *= nums[i];
//         }
//         for (int i = n - 1; i >= 0; i--) {
//             ans[i] = ans[i] * rightProduct;
//             rightProduct *= nums[i];
//         }
//         return ans;
//     }
// };

int main(){
    Solution obj;
    vector<int>nums={1,2,3,4};
    vector<int>ans=obj.productExceptSelf(nums);
    for(auto &it:ans){
        cout<<it<<" ";
    }

    return 0;
}