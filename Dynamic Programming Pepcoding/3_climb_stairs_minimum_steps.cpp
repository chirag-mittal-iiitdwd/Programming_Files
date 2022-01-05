/*
    Given an array which contains the number of jumps we can take from any particular stair
    upto the data stored in the array, ex = {2 , 4, 1, 0, 2, 3}
    Since this array has 6 places so we want to go till 6th stair
    Find minimum possible number of steps to reach end
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int climbStairs(int n,vector<int>&arr){
        vector<int>dp(n+1,INT_MAX-1);
        dp[n]=0;                                  // We dont need ans number of steps to reach from n to n
        for(int i=n-1;i>=0;i--){                  // Going from end of the arr 
            for(int j=1;j<=arr[i] && i+j<=n;j++){ // taking steps from 1 to arr[i]
                dp[i]=min(dp[i],dp[i+j]);         // Taking the minimum value of all possible required steps
            }
            dp[i]++;                              // Increasing by 1 because we took 1 step from current to whatever the minimum might be
        }
        return dp[0];                             // Returning dp[0], it contains min steps from 0 to n
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
    cout<<obj.climbStairs(n,arr)<<endl;
}