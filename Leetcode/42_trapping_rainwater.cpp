#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax(n,0);
        vector<int>rightMax(n,0);
        leftMax[0]=0;
        rightMax[n-1]=0;
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],height[i-1]);
        }

        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i+1]);
        }
        int rain=0;
        for(int i=1;i<=n-2;i++){
            int cur=(min(leftMax[i],rightMax[i]))-height[i];  
            if(cur>0){
                rain+=cur;
            }      
        }

        return rain;
    }

    int trap2(vector<int>&height){
        int n=height.size(),left=0,right=n-1,res=0,maxLeft=0,maxRight=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxLeft){
                    maxLeft=height[left];
                }
                else{
                    res+=maxLeft-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=maxRight){
                    maxRight=height[right];
                }
                else{
                    res+=maxRight-height[right];
                }
                right++;
            }
        }
        return res;
    }
};