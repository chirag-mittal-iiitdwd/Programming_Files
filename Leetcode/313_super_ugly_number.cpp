#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int p=primes.size();
        vector<int>dp(n);
        dp[0]=1;
        unordered_map<int,int>ptrs;
        for(int i=1;i<n;i++){
            vector<int>vals(p);
            int minVal=INT_MAX;
            for(int j=0;j<p;j++){
                vals[j]=ptrs[primes[j]]*primes[j];
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