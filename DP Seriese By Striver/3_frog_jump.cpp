#include<bits/stdc++.h>
using namespace std;

int recursive(vector<int>&nums,int n,int idx){
    if(idx==0){
        return 0;
    }
    int mini=recursive(nums,n,idx-1)+abs(nums[idx]-nums[idx-1]);
    if(idx>1){
        mini=min(mini,recursive(nums,n,idx-2)+abs(nums[idx]-nums[idx-2]));
    }
    return mini;
}

int memo(vector<int>&nums,int n,int idx,vector<int>&dp){
    if(idx==0){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    int mini=recursive(nums,n,idx-1)+abs(nums[idx]-nums[idx-1]);
    if(idx>1){
        mini=min(mini,recursive(nums,n,idx-2)+abs(nums[idx]-nums[idx-2]));
    }
    return dp[idx]=mini;
}

int bottomUp(vector<int>&nums,int n){
    vector<int>dp(n,0);
    for(int i=1;i<n;i++){
        int mini=dp[i-1]+abs(nums[i]-nums[i-1]);
        if(i>1){
            mini=min(mini,dp[i-2]+abs(nums[i]-nums[i-2]));
        }
        dp[i]=mini;
    }
    return dp[n-1];
}

int spaceOpt(vector<int>&nums,int n){
    int prev=0,prev2=0;
    for(int i=1;i<n;i++){
        int mini=INT_MAX;
        mini=prev+abs(nums[i]-nums[i-1]);
        if(i>1){
            mini=min(mini,prev2+abs(nums[i]-nums[i-2]));
        }
        prev2=prev;
        prev=mini;
    }
    return prev;
}

int main(){
    vector<int>nums={30,10,60,10,60,50};
    int n=nums.size();
    vector<int>dp(n+1,-1);
    cout<<recursive(nums,nums.size(),nums.size()-1)<<endl;
    cout<<memo(nums,n,n-1,dp)<<endl;
    cout<<bottomUp(nums,n)<<endl;
    cout<<spaceOpt(nums,n)<<endl;
}