#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>rightMax(n,INT_MIN);
        rightMax[n-1]=prices[n-1];

        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i-1],prices[i]);
        }
        int maxProfit=0;
        for(int i=0;i<n;i++){
            maxProfit=max(maxProfit,rightMax[i]-prices[i]);
        }
        return maxProfit;
    }
};

class Solution2{
    public:
    int maxProfit(vector<int>&prices){
        int mini=INT_MIN;
        int n=prices.size();
        int profit=0;
        for(int i=0;i<n;i++){
            mini=min(mini,prices[i]);
            profit=max(profit,prices[i]-mini);
        }
        return profit;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}