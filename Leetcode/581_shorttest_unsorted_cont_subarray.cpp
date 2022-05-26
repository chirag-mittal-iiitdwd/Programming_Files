#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>temp=nums;
        int n=nums.size();

        sort(temp.begin(),temp.end());
        int r=-1,l=-1;

        for(int i=0;i<n;i++){
            if(nums[i]!=temp[i]){
                if(l==-1){
                    l=i;
                }
                r=i;
            }
        }

        if(r==-1 && l==-1){
            return 0;
        }
        else{
            return r-l+1;        
        }
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start=-1,end=-1,maxi=INT_MIN,n=nums.size();

        for(int i=0;i<n;i++){
            if(maxi>nums[i]){
                if(start==-1){
                    start=i-1;
                }
                while(start-1>=0 && nums[start-1]>nums[i]){
                    start--;
                }
                end=i+1;
            }
            else{
                maxi=nums[i];
            }
        }

        return end-start;
    }
};