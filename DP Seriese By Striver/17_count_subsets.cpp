#include<bits/stdc++.h>
using namespace std;

int recursion(vector<int>&nums,int target,int n){
    if(target==0){
        return 1;
    }
    if(target<0){
        return 0;
    }
    if(n==0){
        return nums[0]==target;
    }
    int notPick=recursion(nums,target,n-1);
    int pick=0;
    if(nums[n]<=target){
        pick=recursion(nums,target-nums[n],n-1);
    }
    return pick+notPick;
}

int spaceOpt(vector<int>&nums,int target,int n){
    vector<int>prev(target+1,0),cur(target+1,0);
    prev[0]=cur[0]=1;
    if(nums[0]<=target){
     prev[nums[0]]=1;   
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            int notTake=prev[j];
            int take=0;
            if(nums[i]<=j){
                take=prev[j-nums[i]];
            }
            cur[j]=take+notTake;
        }
        prev=cur;
    }
    return prev[target];
}