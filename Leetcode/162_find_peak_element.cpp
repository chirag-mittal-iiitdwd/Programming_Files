#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1){
//             return 0;
//         }
//         else if(n==2){
//             if(nums[0]>nums[1]){
//                 return 0;
//             }
//             else{
//                 return 1;
//             }
//         }

//         for(int i=1;i<n-1;i++){
//             if(nums[i-1]<nums[i] && nums[i]>nums[i+1]){
//                 return i;
//             }
//         }
//         return 0;
//     }
// };

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i==0 && i+1<n && nums[i]>nums[i+1]){
                return 0;
            }
            else if(i==n-1 && i-1>=0 && nums[i-1]<nums[i]){
                return n-1;
            }
            else if(i+1<n && i-1>=0 && nums[i-1]<nums[i] && nums[i]>nums[i+1]){
                return i;
            }
        }

        return 0;
    }
};