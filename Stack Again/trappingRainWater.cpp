/*
    Brute Force Solution : Time Complexity O(N^2)
    Space Somplexity : O(1)
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            calculate left max
        }
        for(int j=n-1;j>i;j--){
            calculate right max
        }
        res+=((min(leftMax,rightMax))-arr[i]);
    }
    return res;

    More Optimised code
    Time Complexity : O(3N)
    Space Complexity : O(2N)
    int rightMax[n],leftMax[n];
    for(int i=0;i<n;i++){
        store the left max into left max array
    }

    for(int i=n-1;i>=0;i--){
        store the right max into right max array
    }
    for(int i=0;i<n;i++){
        ans+=min(leftMax[i],rightMax[i])-arr[i];
    }
*/
#include<bits/stdc++.h>
using namespace std;

// Most Optimal approach : two pointer approach
// First explain the logic than code

int trap(vector<int>height){
    int n=height.size(),left=0,right=n-1,res=0,maxLeft=0,maxRight=0;
    while(left<=right){
        if(height[left]<=height[right]){
            if(height[left]>=maxLeft){
                maxLeft=height[left];
            }
            else{
                res+=(maxLeft-height[left]);
            }
            left++;
        }
        else{
            if(height[right]>=maxRight){
                maxRight=height[right];
            }
            else{
                res+=(maxRight-height[right]);
            }
            right--;
        }
    }
}