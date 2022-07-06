#include<bits/stdc++.h>
using namespace std;

int spaceOpt(vector<int>&nums,int n){
    int target=accumulate(nums.begin(),nums.end(),0);
    vector<bool>prev(target+1,false),cur(target+1,false);
    prev[0]=cur[0]=true;
    prev[nums[0]]=true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool notTake=prev[j];
            bool take=false;
            if(nums[i]<=j){
                take=prev[j-nums[i]];
            }
            cur[j]=take|notTake;
        }
        prev=cur;
    }
    
    int miniDiff=target;
    for(int i=0;i<=target;i++){
        if(prev[i]){
            int first=i;
            int second=target-i;
            miniDiff=min(miniDiff,abs(first-second));
        }

    }

    return miniDiff;
}