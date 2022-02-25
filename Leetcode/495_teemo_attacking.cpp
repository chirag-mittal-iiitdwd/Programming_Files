#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        timeSeries.push_back(INT_MAX);
        int n=timeSeries.size();

        int ans=0;
        for(int i=0;i<n-1;i++){
            if((timeSeries[i+1]-timeSeries[i])>=duration){
                ans+=duration;
            }
            else{
                ans+=timeSeries[i+1]-timeSeries[i];
            }
        }
        return ans;
    }
};