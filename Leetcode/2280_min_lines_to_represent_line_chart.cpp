#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n=stockPrices.size();
        if(n==1 || n==2){
            return n-1;
        }

        sort(stockPrices.begin(),stockPrices.end(),[&](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });

        int cnt=1;
        for(int i=2;i<n;i++){
            int x1=stockPrices[i][0],x2=stockPrices[i-1][0],x3=stockPrices[i-2][0];
            int y1=stockPrices[i][1],y2=stockPrices[i-1][1],y3=stockPrices[i-2][1];

            long long int diff1=(y3-y2)*(x2-x1);
            long long int diff2=(y2-y1)*(x3-x2);
            if(diff1!=diff2){
                cnt++;
            }
        }

        return cnt;
    }
};

class Solution {
public:
    int minimumLines(vector<vector<int>>& stk) {
        sort(stk.begin(),stk.end());
        int n = stk.size();
        if(n==1)
            return 0;
        int cnt = 1;
        for(int i=2;i<n;i++){
            long x1 = stk[i][0],x2 = stk[i-1][0],x3 = stk[i-2][0];
            long y1 = stk[i][1],y2 = stk[i-1][1],y3 = stk[i-2][1];
            long diff1 = (y3-y2) * (x2-x1);
            long diff2 = (y2-y1) * (x3-x2);
            if(diff1 != diff2)
                cnt++;
        }
        
        return cnt;
    }
};