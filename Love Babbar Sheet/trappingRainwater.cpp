/*
    https://www.youtube.com/watch?v=m18Hntz4go8
    For brute force approach we can check for every index and them add the answer
    water stored at any index = min(max of left building,max of right building)-the height of the current index

    This will have time complexity of O(n^2)
    because max of left building will traverse through i to 0
    and max of right will go from i to n-1

    the optimal solution is to use prefix sum
    storing the max of left building into prefix array
    storing the max of right building into suffix array by doing some precomputations
    Time Complexity = O(N)    Space Complexity = O(2N)
    More Optimal?

    Yes, by two pointer approach
    In interview first explain the logic then explain the thought process behind it
    left=0, right=0, leftMax=0, rightMax=0, water=0

    if(arr[left]<=arr[right]){
        if(arr[left]>=leftMax){
            leftMax=arr[i];
            l++;
        }
        else{
            water+=(leftMax-arr[i]);
            l++;
        }
    }
    else{
        if(arr[right]>=rightMax){
            rightMax=arr[right];
            r--;
        }
        else{
            water+=(rightMax-arr[i]);
            r--;
        }
    }

    The reason why this algorithm works is that by checking (arr[left]<=arr[right]) we are 
    making sure that that right is bigger so water will definatey will be stored in the block
    that is why we can do water+=(leftMax-arr[i]) without bothing about the right
        similar case for the right part we are making sure that left part is bigger when we
    want to add water to the result and dont bother about left water+=(rightMax-arr[i])

    Time Complexity = O(N)      Space complexity = O(1)
*/

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int trappingWater(vector<int>height){
        int n=height.size();
        int left=0,right=n-1,res=0,maxLeft=0,maxRight=0;
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
        return res;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution obj;
    cout<<obj.trappingWater(arr);
}