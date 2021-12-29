#include<bits/stdc++.h>
using namespace std;

class Solution {
    int arr[46]={0};
    public:
    int climbStairs(int n){
        if(n<=1){
            return 1;
        }
        if(arr[n]!=0){
            return arr[n];
        }
        else{
            arr[n]+=climbStairs(n-1)+climbStairs(n-2);
        }
        return arr[n];
    }
};