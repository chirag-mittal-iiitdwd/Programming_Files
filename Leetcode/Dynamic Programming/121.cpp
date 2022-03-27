#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX,n=prices.size(),maxProfit=0;

        for(int i=0;i<n;i++){
            mini=min(mini,prices[i]);
            maxProfit=max(maxProfit,prices[i]-mini);
        }

        return maxProfit;
    }

};