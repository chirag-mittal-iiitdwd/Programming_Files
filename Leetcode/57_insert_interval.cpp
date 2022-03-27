#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        
        if(n==0 || intervals[n-1][1]<newInterval[0]){
            intervals.push_back(newInterval);
            return intervals;
        }

        int startIdx=-1;
        int endIdx=-1;
        if(intervals[0][1]>newInterval[1]){
            intervals.insert(intervals.begin(),newInterval);
            return intervals;
        }
        if(intervals[0][0]>newInterval[0]){
            startIdx=0;
        }
        for(int i=0;i<n;i++){
            if(intervals[i][0]<=newInterval[0]){
                startIdx=i;
            }
            if(intervals[i][0]<=newInterval[1]){
                endIdx=i;
            }
        }

        // if(startIdx==-1){
        //     intervals.push_back(newInterval);
        //     return intervals;
        // }

        vector<vector<int>>ans;
        for(int i=0;i<startIdx;i++){
            ans.push_back(intervals[i]);
        }

        int smallerFirst=min(intervals[startIdx][0],newInterval[0]);
        int biggerLast=max(intervals[endIdx][1],newInterval[1]);
        ans.push_back({smallerFirst,biggerLast});

        for(int i=endIdx+1;i<n;i++){
            ans.push_back(intervals[i]);
        }

        return ans;
    }
};