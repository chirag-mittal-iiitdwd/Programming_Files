
// https://www.youtube.com/watch?v=LuLCLgMElus
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),k,l;
        for(k=n-2;k>=0;k--){
            if(nums[k]<nums[k+1]){
                break;
            }
        }
        if(k<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(l=n-1;l>k;l--){
                if(nums[l]>nums[k]){
                    break;
                }
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
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
            cin>>nums[i];
        }
        Solution obj;
        // for(int i=0;i<)
        obj.nextPermutation(nums);
        for(auto &it:nums){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}