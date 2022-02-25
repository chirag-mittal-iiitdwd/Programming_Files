#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();

        int cur=nums[0],cnt=1;
        for(int i=1;i<n;i++){
            if(cur==nums[i]){
                cnt++;
                if(cnt>2){
                    nums.erase(nums.begin()+i);
                    cnt--;
                    i--;
                    n--;
                }
            }
            else{
                cur=nums[i];
                cnt=1;
            }
        }
        return nums.size();
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return n;
        }

        int cnt=1,j=1,prev=nums[0];

        for(int i=1;i<nums.size();i++){
            if(prev==nums[i]){
                cnt++;
                if(cnt>2){
                    continue;
                }
            }
            else{
                cnt=1;
                prev=nums[i];
            }

            swap(nums[i],nums[j]);
            j++;
        }
        return j;
    }
};

