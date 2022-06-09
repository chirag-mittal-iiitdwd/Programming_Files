#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0]=1;
        int ptr2=0,ptr3=0,ptr5=0;

        for(int i=1;i<n;i++){
            int two=dp[ptr2]*2,three=dp[ptr3]*3,five=dp[ptr5]*5;
            dp[i]=min(two,min(three,five));
            if(dp[i]==two){
                ptr2++;
            }
            if(dp[i]==three){
                ptr3++;
            }
            if(dp[i]==five){
                ptr5++;
            }
        }

        return dp[n-1];
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>primes={2,3,5};
        int p=primes.size();
        vector<int>dp(n);
        dp[0]=1;
        unordered_map<int,int>ptrs;
        for(int i=1;i<n;i++){
            vector<int>vals(p);
            int minVal=INT_MAX;
            for(int j=0;j<p;j++){
                vals[j]=dp[ptrs[primes[j]]]*primes[j];
                minVal=min(minVal,vals[j]);
            }
            dp[i]=minVal;

            for(int j=0;j<p;j++){
                if(vals[j]==minVal){
                    ptrs[primes[j]]++;
                }
            }
        }
        return dp[n-1];
    }
};