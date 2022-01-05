/*
    Given an array which contains the number of jumps we can take from any particular stair
    upto the data stored in the array, ex = {2 , 4, 1, 0, 2, 3}
    Since this array has 6 places so we want to go till 6th stair
    Find total possible ways for reaching at top
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int climbStairs(int n,vector<int>&arr){
        vector<int>dp(n+1,-1);
        dp[n]=1;                                    // Only 1 way of going from n to n
        for(int i=n-1;i>=0;i--){                    // traversing through the steps array from the end 
            for(int j=1;j<=arr[i] && i+j<n+1;j++){  // taking steps from 1 to arr[i] and adding the steps to dp[i]
                dp[i]+=dp[i+j];                           
            }
        }
        return dp[0];                               // Returning dp[0], it contains total ways of going from 0 to n 
    }
};

