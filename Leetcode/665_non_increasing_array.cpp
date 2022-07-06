#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        
        bool flag=false;
        for(int i=0;i<n;i++){
            int lowerLim=INT_MIN,upperLim=INT_MAX;
            if(i==0){
                if(n>1){
                    upperLim=nums[i+1];
                }
            }
            else if(i>0 && i<n-1){
                upperLim=nums[i+1],lowerLim=nums[i-1];
            }
            else{
                upperLim=INT_MAX,lowerLim=nums[i-1];
            }
            if(!(nums[i]>=lowerLim && nums[i]<=upperLim) && flag){
                return false;
            }
            if(!(nums[i]>=lowerLim && nums[i]<=upperLim)){
                nums[i]=lowerLim;
                flag=true;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int error=0,n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                if(error || (i>1 && i<n-1 && nums[i-2]>nums[i] && nums[i-1]>nums[i+1])){
                    return false;
                }
                error++;
            }
        }

        return true;
    }
};